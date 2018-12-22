#include <iostream>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QPainter>

#include "chemhelper.h"
#include "ui_chemhelper.h"
#include "ch_variables_and_types.h"
#include "ch_graphics.h"

using namespace std;

ChemHelper::ChemHelper(QWidget *parent) : QMainWindow(parent), ui(new Ui::ChemHelper)
{
    ui->setupUi(this);
    MonitorWidth = QApplication::desktop()->width();
    MonitorHeight = QApplication::desktop()->height();
    HWbtnSearch = min(MonitorWidth, MonitorHeight) / 30;

    QString filename = "..\\data\\images\\SearchButton.jpg";
    QClickableLabel *lblSearchButton = new QClickableLabel;
    lblSearchButton->setAlignment(Qt::AlignCenter);
    lblSearchButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    lblSearchButton->setFixedSize(HWbtnSearch, HWbtnSearch);
    lblSearchButton->setScaledContents(true);
    lblSearchButton->setCursor(Qt::PointingHandCursor);
    connect(lblSearchButton, SIGNAL(clicked()), this, SLOT(on_btnSearch_clicked()));
    QPixmap pix;
    if(pix.load(filename))
    {

        //pix = pix.scaled(btnSearch->size(),Qt::KeepAspectRatio);
        lblSearchButton->setPixmap(pix);
        //ui->label->setPixmap(pix);
    }
    ui->ltGoogleEdit->addWidget(lblSearchButton);

    QShape *rctUnderscore = new QShape;
    QPainter brush(this);
    rctUnderscore->setHeight(50);
    rctUnderscore->setWidth(100);
    rctUnderscore->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    brush.setPen(Qt::red);
    brush.drawRect(*rctUnderscore);
    ui->ltGoogleEdit->addWidget(rctUnderscore);
}

ChemHelper::~ChemHelper()
{
    delete ui;
}

/*void /*TForm1.tmrProcessTimingTimer()
{
    int UTC;
    int Now;
    GetSystemTime(UTC);
    Now = SysTimeToInt(UTC);
    if (Now - TimeEditAnimationStart > EditAnimationTime && EditAnimationRunning)
    {
        EditAnimationRunning = false;
        SetEditFinishPosition();
    }
    if (Now - TimeEditInverseAnimationStart > EditAnimationTime && EditInverseAnimationRunning)
    {
        EditInverseAnimationRunning = false;
        SetEditStartPosition();
    }
    if (Now - TimeAllAnimationStart > AllAnimationTime && AllAnimationRunning)
        AllAnimationRunning = false;
    if (Now - TimeAllInverseAnimationStart > AllAnimationTime && AllInverseAnimationRunning)
        AllInverseAnimationRunning = false;
    Redraw();
}


void /*TForm1.FormCreate()
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
    for(long long i = 0; i < 1000000000; i++);
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
    sendRequest(ui->edtInputFormula->text().toStdString());
}

bool ChemHelper::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->edtInputFormula)
    {
        switch (event->type())
        {
        case QEvent::KeyPress :
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            switch(keyEvent->key())
            {
            case 13:
                if(sendRequest(ui->edtInputFormula->text().toStdString()))
                {

                }
                break;
            case 27:
                if (ui->edtInputFormula->text() == "")
                    ui->edtInputFormula->setText("Ваша формула");
                LaunchEditInverseAnimation;
                break;
            }

            break;
        }
        case QEvent::FocusIn:
        {
            break;
        }
        case QEvent::FocusOut:
        {
            break;
        }
        }
    }
}
