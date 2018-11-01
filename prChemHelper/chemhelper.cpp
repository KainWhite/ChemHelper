#include "chemhelper.h"
#include "ui_chemhelper.h"

ChemHelper::ChemHelper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChemHelper)
{
    ui->setupUi(this);
}

ChemHelper::~ChemHelper()
{
    delete ui;
}
