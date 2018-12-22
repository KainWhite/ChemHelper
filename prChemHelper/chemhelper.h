#ifndef CHEMHELPER_H
#define CHEMHELPER_H

#include <QMainWindow>

namespace Ui
{
    class ChemHelper;
}

class ChemHelper : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChemHelper(QWidget *parent = nullptr);
    ~ChemHelper();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void on_btnSearch_clicked();

private:
    Ui::ChemHelper *ui;
};

#endif // CHEMHELPER_H
