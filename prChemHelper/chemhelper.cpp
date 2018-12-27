#include <iostream>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <cmath>
#include <windows.h>

#include "chemhelper.h"
#include "ui_chemhelper.h"
#include "ch_variables_and_types.h"
#include "ch_model.h"

using namespace std;

ChemHelper::ChemHelper(QWidget *parent) : QMainWindow(parent), ui(new Ui::ChemHelper), tmrProcessTimig(new QTimer), nam(new QNetworkAccessManager)
{
    MonitorWidth = QApplication::desktop()->width();
    MonitorHeight = QApplication::desktop()->height();
    btnSearchWidth = min(MonitorWidth, MonitorHeight) / 30;

    ui->setupUi(this);

    tmrProcessTimig->setInterval(15);
    connect(tmrProcessTimig, SIGNAL(timeout()), this, SLOT(update()));
    tmrProcessTimig->start();

    ui->gviewUnderscore->setScene(new QGraphicsScene);
    ui->gviewUnderscore->setBackgroundBrush(QBrush(UnderscoreCorrectColor, Qt::SolidPattern));

    ui->ltGEdit->setAlignment(ui->gviewUnderscore, Qt::AlignHCenter);

    QString filename = "..\\data\\images\\SearchButton.jpg";
    QClickableLabel *lblSearchButton = new QClickableLabel(this);
    lblSearchButton->setAlignment(Qt::AlignCenter);
    lblSearchButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    lblSearchButton->setFixedSize(btnSearchWidth, btnSearchWidth);
    lblSearchButton->setScaledContents(true);
    lblSearchButton->setCursor(Qt::PointingHandCursor);
    //lblSearchButton->setGeometry(100, 200, 0, 0);
    connect(lblSearchButton, SIGNAL(clicked()), this, SLOT(on_btnSearch_clicked()));
    QPixmap pix;
    if(pix.load(filename))
        lblSearchButton->setPixmap(pix);
    ui->ltGEB->addWidget(lblSearchButton);

    ui->twSearchResults->setEditTriggers(QAbstractItemView::NoEditTriggers);

    qApp->installEventFilter(this);
    initializeVariables(*(ui->GEdit), *(ui->gviewUnderscore), *(ui->lblLogo), *(ui->twSearchResults));
    ui->edtInputFormula->clearFocus();
}

ChemHelper::~ChemHelper()
{
    delete ui;
    delete tmrProcessTimig;
}

void ChemHelper::update()
{
    SYSTEMTIME UTC;
    GetSystemTime(&UTC);
    long long now = sysTimeToInt(UTC);
    sysTimeToInt(UTC);
    if (now - TimeGEditAnimationStart > GEditAnimationTime && GEditAnimationRunning)
        gEditAnimationFinished(*(ui->gviewUnderscore));
    if (now - TimeGEditInverseAnimationStart > GEditAnimationTime && GEditInverseAnimationRunning)
        gEditInverseAnimationFinished(*(ui->gviewUnderscore));
    if (now - TimeAllAnimationStart > AllAnimationTime && AllAnimationRunning)
        allAnimationFinished(*(ui->GEdit), *(ui->lblLogo), *(ui->twSearchResults));
    if (now - TimeAllInverseAnimationStart > AllAnimationTime && AllInverseAnimationRunning)
        allInverseAnimationFinished(*(ui->GEdit), *(ui->lblLogo), *(ui->twSearchResults));
    if(GEditAnimationRunning || GEditInverseAnimationRunning || AllAnimationRunning || AllInverseAnimationRunning)
        needRedraw(*(ui->GEdit), *(ui->gviewUnderscore), *(ui->lblLogo), *(ui->twSearchResults));
}

wstring vectorWStringToWString(const vector<wstring> &src)
{
    wstring result = L"";
    for(int i = 0; i < src.size(); i++)
        result.append(src[i]);
    return result;
}

void ChemHelper::fillTWSearchResults(const std::wstring &HTMLCode)
{
    int i = 0;
    bool divgOpened = false, h3Opened = false, aOpened = false, citeOpened = false;
    int countDivOpened = 0;
    vector<wstring> titles, URLs;
    while (i < HTMLCode.size())
    {
        //wcout<<HTMLCode[i]<<endl;
        //ShowMessage(IntToStr(i) + backNSymbols(i, 6, HTMLCode));
        if (divgOpened && forwardNSymbols(i, 6, HTMLCode) == L"</div>" && countDivOpened == 1)
        {
            divgOpened = false;
            countDivOpened--;
        }
        if (countDivOpened > 0 && forwardNSymbols(i, 6, HTMLCode) == L"</div>")
            countDivOpened--;

            if (citeOpened && HTMLCode[i] == '<')
            {
                if (forwardNSymbols(i, 7, HTMLCode) == L"</cite>")
                    citeOpened = false;
                else
                {
                    shiftUntilX(i, '>', HTMLCode);
                    i++;
                }
            }

                if (citeOpened)
                {
                    URLs.push_back(shiftUntilX(i, '<', HTMLCode));
                    i--;
                }

            if (divgOpened && backNSymbols(i, 5, HTMLCode) == L"<cite")
            {
                shiftUntilX(i, '>', HTMLCode);
                citeOpened = true;
            }
            if (aOpened && forwardNSymbols(i, 4, HTMLCode) == L"</a>")
                aOpened = false;

                if (h3Opened && HTMLCode[i] == '<')
                {
                    if (forwardNSymbols(i, 5, HTMLCode) == L"</h3>")
                        h3Opened = false;
                    else
                    {
                        shiftUntilX(i, '>', HTMLCode);
                        i++;
                    }
                }

                    if (h3Opened)
                    {
                        titles.push_back(shiftUntilX(i, '<', HTMLCode));
                        if ( titles.back().size() > 30 )
                        {
                            titles.back().erase(30, titles.size() - 30);
                            titles.back() += L"...";
                            aOpened = false;
                        }
                        i--;
                    }

                if (aOpened && backNSymbols(i, 3, HTMLCode) == L"<h3")
                {
                    shiftUntilX(i, '>', HTMLCode);
                    h3Opened = true;
                }

            if (divgOpened && backNSymbols(i, 2, HTMLCode) == L"<a")
            {
                shiftUntilX(i, '>', HTMLCode);
                aOpened = true;
            }

        if (countDivOpened > 0 && backNSymbols(i, 4, HTMLCode) == L"<div")
            countDivOpened++;
        if (backNSymbols(i, 14, HTMLCode) == L"<div class=\"g\"")
        {
            //cout<<"kek"<<endl;
            shiftUntilX( i, '>', HTMLCode );
            divgOpened = true;
            countDivOpened = 1;
        }
        i++;
    }
    /*for(int i = 0; i < titles.size(); i++)
    {
        wcout << QString::fromStdWString(titles[i]).toStdWString() << L" " << URLs[i] << endl;
    }*/
    for (int i = 0; i < titles.size(); i++)
    {
        ui->twSearchResults->insertRow(ui->twSearchResults->rowCount());
        ui->twSearchResults->setRowHeight(ui->twSearchResults->rowCount() - 1, 50);
        //titles[i] = L"ывамыфывфыdfsdfvsdfваьидла";
        //titles[i] = QString::fromStdWString(titles[i]).toStdWString();
        QTableWidgetItem *x = new QTableWidgetItem(QString::fromStdWString(titles[i]));
        //wcout << x->text().toStdWString() << endl;
        ui->twSearchResults->setItem(ui->twSearchResults->rowCount() - 1, 0, x);
        if (forwardNSymbols(0, 4, URLs[i]) == L"http")
            ui->twSearchResults->setItem(ui->twSearchResults->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdWString(URLs[i])));
        else
            ui->twSearchResults->setItem(ui->twSearchResults->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdWString(L"http://" + URLs[i])));
    }
}

void ChemHelper::searchFinished()
{
    wstring HTML(reply->readAll().toStdString().begin(), reply->readAll().toStdString().end());
    wcout<<HTML<<endl;
    fillTWSearchResults(HTML);
}

void ChemHelper::sendRequest(const string &inputFormula)
{
    ui->twSearchResults->clear();
    ui->twSearchResults->setRowCount(0);
    /*for(int i = 0; i < CiteArray.size(); i++)
    {                                                                                                     CHANGE TO I
        reply = nam->get(QNetworkRequest(QUrl(QString::fromStdString("https://www.google.com/search?q=" + CiteArray[0] + inputFormula))));
    }
    QObject::connect(reply, SIGNAL(finished()), this, SLOT(searchFinished()));*/
    //cout<<inputFormula<<endl;
    long long cnt = 0;
    for(long long i = 0; i < 3500000000; i++)
    {
        cnt+=i;
    }
    cout<<cnt<<endl;
    if(inputFormula == "H2O")
    {
        //cout<<"kek"<<endl;
        //wcout<<vectorWStringToWString(HTMLH2O)<<endl;
        fillTWSearchResults(vectorWStringToWString(HTMLH2O));
    }
    if(inputFormula == "HCl")
    {
        fillTWSearchResults(vectorWStringToWString(HTMLHCl));
    }
    if(inputFormula == "Al2(SO4)3")
    {
        fillTWSearchResults(vectorWStringToWString(HTMLAl2SO43));
    }
    //SrchResFinishHeight = min(SrchResFinishHeight, ui->twSearchResults->rowCount() * 50 + 20);
    launchAllAnimation();
}

void ChemHelper::on_btnSearch_clicked()
{
    if(isValidChemical(ui->edtInputFormula->toPlainText().toStdString()))
    {
        ui->edtInputFormula->clearFocus();
        //cout<<ui->edtInputFormula->toPlainText().toStdString()<<endl;
        sendRequest(normallize(ui->edtInputFormula->toPlainText().toStdString()));
    }
    else
    {
        ui->gviewUnderscore->setBackgroundBrush(QBrush(UnderscoreWrongColor, Qt::SolidPattern));
        WasGEditAnimation = false;
        launchGEditAnimation();
        WasChangedInputFormula = false;
    }
}

bool isValidKey(int key)
{
    /*
     * 16777220 - enter
     * 16777216 - esc
     * 16777219 - backspase
     * 16777223 - del
     * 16777(234, 235, 236, 237) - arrows (l, u, r, d)
     * 40 .. 43 - '(', ')', '*', '+'
     * 61 - '='
     * 32 - ' '
     * 91 - '['
     * 93 - ']'
    */
    return (isKNumber(key) || isKLetter(key) ||
            key == 16777220 || key == 16777216 || key == 16777219 || key == 16777223 ||
            key == 16777234 || key == 16777235 || key == 16777236 || key == 16777237 ||
            (key >= 40 && key <= 43) || key == 61 || key == 32 || key == 91 || key == 93);
}

bool ChemHelper::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->edtInputFormula)
    {
        switch (event->type())
        {
        case QEvent::KeyPress :
        {
            int key = (static_cast<QKeyEvent*>(event))->key();
            //cout<<key<<endl;
            if(!isValidKey(key))
                return true;
            if(key == 16777220) // enter
            {
                emit(on_btnSearch_clicked());
                return true;
            }
            if(key == 16777216) //esc
                QCoreApplication::postEvent(watched, new QEvent(QEvent::FocusOut));
            else
            {
                ui->gviewUnderscore->setBackgroundBrush(QBrush(UnderscoreCorrectColor, Qt::SolidPattern));
                needRedraw(*(ui->GEdit), *(ui->gviewUnderscore), *(ui->lblLogo), *(ui->twSearchResults));
            }
            if(isKNumber(key))
                ui->edtInputFormula->setCurrentFont(QFont("Comic Sans MS", 6));
            if(isKLetter(key) || (key >= 40 && key <= 43) || key == 61 || key == 32 || key == 91 || key == 93)
                ui->edtInputFormula->setCurrentFont(QFont("Comic Sans MS", 12));
            break;
        }
        case QEvent::FocusIn:
        {
            gEditFocusIn(*(ui->edtInputFormula));
            break;
        }
        case QEvent::FocusOut:
        {
            gEditFocusOut(*(ui->edtInputFormula));
            ui->edtInputFormula->clearFocus();
            break;
        }
        }
    }
    return QObject::eventFilter(watched, event);
}

void ChemHelper::on_twSearchResults_cellClicked(int row, int column)
{
    const char *url = ui->twSearchResults->item(row, 1)->text().toUtf8();
    const char *open = "open";
    ShellExecuteA(NULL, open, url ,  NULL,  NULL, SW_HIDE);
}
