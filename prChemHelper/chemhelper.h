#ifndef CHEMHELPER_H
#define CHEMHELPER_H

#include <QMainWindow>

namespace Ui {
class ChemHelper;
}

class ChemHelper : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChemHelper(QWidget *parent = nullptr);
    ~ChemHelper();

private:
    Ui::ChemHelper *ui;
};

#endif // CHEMHELPER_H
