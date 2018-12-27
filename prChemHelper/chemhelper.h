#ifndef CHEMHELPER_H
#define CHEMHELPER_H

#include <QMainWindow>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>

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
    void sendRequest(const std::string &inputFormula);
    void fillTWSearchResults(const std::wstring &HTML);

protected:
    bool eventFilter(QObject *watched, QEvent *event); //override;

private slots:
    void on_btnSearch_clicked();
    void searchFinished();
    void update();

    void on_twSearchResults_cellClicked(int row, int column);

private:
    Ui::ChemHelper *ui;
    QTimer *tmrProcessTimig;
    QNetworkAccessManager *nam;
    QNetworkReply *reply;
};

#endif // CHEMHELPER_H
