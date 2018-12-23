#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "chemhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChemHelper w;
    w.show();
    return a.exec();
}
