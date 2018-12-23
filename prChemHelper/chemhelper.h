#ifndef CHEMHELPER_H
#define CHEMHELPER_H

#include <QMainWindow>
#include <QTimer>

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
    bool eventFilter(QObject *watched, QEvent *event); //override;

private slots:
    void on_btnSearch_clicked();
    void update();

private:
    Ui::ChemHelper *ui;
    QTimer *tmrProcessTimig;
};

#endif // CHEMHELPER_H
