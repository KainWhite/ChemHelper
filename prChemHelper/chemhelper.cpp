#include <iostream>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFontDatabase>
#include <QDateTime>

#include "chemhelper.h"
#include "ui_chemhelper.h"
#include "ch_variables_and_types.h"
#include "ch_model.h"

using namespace std;

ChemHelper::ChemHelper(QWidget *parent) : QMainWindow(parent), ui(new Ui::ChemHelper), tmrProcessTimig(new QTimer)
{
    MonitorWidth = QApplication::desktop()->width();
    MonitorHeight = QApplication::desktop()->height();
    HWbtnSearch = min(MonitorWidth, MonitorHeight) / 30;

    ui->setupUi(this);

    tmrProcessTimig->setInterval(15);
    connect(tmrProcessTimig, SIGNAL(timeout()), this, SLOT(update()));
    tmrProcessTimig->start();

    ui->gviewUnderscore->setFixedWidth(100);

    ui->ltGEdit->setAlignment(ui->gviewUnderscore, Qt::AlignHCenter);

    QString filename = "..\\data\\images\\SearchButton.jpg";
    QClickableLabel *lblSearchButton = new QClickableLabel(this);
    lblSearchButton->setAlignment(Qt::AlignCenter);
    lblSearchButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    lblSearchButton->setFixedSize(HWbtnSearch, HWbtnSearch);
    lblSearchButton->setScaledContents(true);
    lblSearchButton->setCursor(Qt::PointingHandCursor);
    //lblSearchButton->setGeometry(100, 200, 0, 0);
    connect(lblSearchButton, SIGNAL(clicked()), this, SLOT(on_btnSearch_clicked()));
    QPixmap pix;
    if(pix.load(filename))
        lblSearchButton->setPixmap(pix);
    ui->ltGEB->addWidget(lblSearchButton);

    qApp->installEventFilter(this);
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
    if (now - TimeGEditAnimationStart > GEditAnimationTime && GEditAnimationRunning)
        gEditAnimationFinished();
    if (now - TimeGEditInverseAnimationStart > GEditAnimationTime && GEditInverseAnimationRunning)
        gEditInverseAnimationFinished();
    if (now - TimeAllAnimationStart > AllAnimationTime && AllAnimationRunning)
        allAnimationFinished();
    if (now - TimeAllInverseAnimationStart > AllAnimationTime && AllInverseAnimationRunning)
        allInverseAnimationFinished();
    if(GEditAnimationRunning || GEditInverseAnimationRunning || AllAnimationRunning || AllInverseAnimationRunning)
        needRedraw();
}


/*void TForm1.FormCreate()
{
    //HideCaret(edtInputFormula.Handle);
    InitializeVariables();
    //open elements in ElementList
}

void /*TForm1.edtInputFormulaClick()
{
    int UTC;
    if (edtInputFormula.Text == "Ваша формула")
        edtInputFormula.Text = "";
    LaunchEditAnimation();
}

void /*TForm1.edtInputFormulaExit()
{
    int UTC;
    imgInvalidFormula.Visible = False;
    if (edtInputFormula.Text == "")
        edtInputFormula.Text = "Ваша формула";
    LaunchEditInverseAnimation;
}
*/
int sendRequest(string inputFormula)
{
    //strngrdSearchResults.RowCount = 0;
    /*InputFormula = Normallize(InputFormula);
    if (!IsValidChemical(InputFormula) && AnsiPos(InputFormula, ExceptionList) == 0)
    {
        //ShowMessageInvalidInputFormula;
        shpLine.Pen.Color = RGB(255, 50, 50);
        shpLine.Brush.Color = RGB(255, 50, 50);
        return;
    }
    if (!CanAccessInternet)
    {
        ShowMessage("Нет соединения с интернетом.");
        return;
    }
    FillSGResults(edtInputFormula.Text);
    LaunchAllAnimation();*/
}
/*
void /*TForm1.edtInputFormulaKeyPress()
{
    TRect R;
    string CurrentInputFormula;
    set<char> AllowedKeys = ['0'..'9', 'a'..'z', 'A'..'Z', '(', ')', '[', ']', ' ', '*', #127, #8];
    WasChangedInputFormula = True;
    if (Key == #13)
        SendRequest(edtInputFormula.Text);
    imgInvalidFormula.Visible = False;
    if (AllowedKeys.find(Key) == AllowedKeys.size())
    {
        Key = #0;
        WasChangedInputFormula = False;
    }
    if (WasChangedInputFormula)
    {
        shpLine.Pen.Color = RGB(102, 102, 255);
        shpLine.Brush.Color = RGB(102, 102, 255);
    }
    /*if (IsNumber(Key)) and (Last(edtInputFormula.Text) <> 'x') and (Last(edtInputFormula.Text) <> 'X') and
                (Last(edtInputFormula.Text) <> '*') and (Last(edtInputFormula.Text) <> ' ')  then
                edtInputFormula.Font.Height := 10
            else
            edtInputFormula.Font.Height := 20;
}

void /*TForm1.FormPaint()
{
    if (WasJustCreated)
    {
        Form1.FocusControl(NULL);
        WasJustCreated = False;
    }
}

void /*TForm1.strngrdSearchResultsSelectCell()
{
    ShellExecute(Handle, 'open', PAnsiChar(strngrdSearchResults.Cells[1, ARow]), NULL, NULL, SW_HIDE);
    //CanSelect := False;
}

void /*TForm1.imgSearchButtonClick()
{
    //TForm1.edtInputFormulaExit(Sender);
    SendRequest(edtInputFormula.Text);
}*/



void ChemHelper::on_btnSearch_clicked()
{
    if(isValidChemical)
        sendRequest(ui->edtInputFormula->toPlainText().toStdString());
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
            if(key == 13) // enter
            {
                //processRequest(ui->edtInputFormula->toPlainText().toStdString());
                gEditFocusOut(*(ui->edtInputFormula));
            }
            if(key == 27) //esc
                QCoreApplication::postEvent(watched, new QEvent(QEvent::FocusOut));
            if(key >= 48 && key <= 57) //numbers
                ui->edtInputFormula->setCurrentFont(QFont("Comic Sans MS", 6));
            if((key >= 65 && key <= 90) || //letters
                    (key >= 33 && key <= 42 && key != 34 && key != 39) || key == 64 || key == 94) //numbers with shift
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
            break;
        }
        }
    }
    return QObject::eventFilter(watched, event);
}
