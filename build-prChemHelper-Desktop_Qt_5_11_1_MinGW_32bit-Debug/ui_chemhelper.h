/********************************************************************************
** Form generated from reading UI file 'chemhelper.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHEMHELPER_H
#define UI_CHEMHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChemHelper
{
public:
    QWidget *centralWidget;
    QWidget *wdgtGEdit;
    QHBoxLayout *ltGEB;
    QVBoxLayout *ltGEdit;
    QTextEdit *edtInputFormula;
    QGraphicsView *gviewUnderscore;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuHelp;

    void setupUi(QMainWindow *ChemHelper)
    {
        if (ChemHelper->objectName().isEmpty())
            ChemHelper->setObjectName(QStringLiteral("ChemHelper"));
        ChemHelper->resize(965, 577);
        ChemHelper->setCursor(QCursor(Qt::ArrowCursor));
        ChemHelper->setWindowOpacity(1);
        ChemHelper->setAutoFillBackground(false);
        ChemHelper->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        ChemHelper->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(ChemHelper);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        wdgtGEdit = new QWidget(centralWidget);
        wdgtGEdit->setObjectName(QStringLiteral("wdgtGEdit"));
        wdgtGEdit->setGeometry(QRect(270, 240, 404, 58));
        ltGEB = new QHBoxLayout(wdgtGEdit);
        ltGEB->setSpacing(7);
        ltGEB->setContentsMargins(11, 11, 11, 11);
        ltGEB->setObjectName(QStringLiteral("ltGEB"));
        ltGEB->setSizeConstraint(QLayout::SetMinimumSize);
        ltGEdit = new QVBoxLayout();
        ltGEdit->setSpacing(0);
        ltGEdit->setObjectName(QStringLiteral("ltGEdit"));
        ltGEdit->setSizeConstraint(QLayout::SetMinimumSize);
        edtInputFormula = new QTextEdit(wdgtGEdit);
        edtInputFormula->setObjectName(QStringLiteral("edtInputFormula"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edtInputFormula->sizePolicy().hasHeightForWidth());
        edtInputFormula->setSizePolicy(sizePolicy);
        edtInputFormula->setMinimumSize(QSize(0, 50));
        edtInputFormula->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(12);
        edtInputFormula->setFont(font);
        edtInputFormula->setStyleSheet(QLatin1String("background-color: rgb(245, 245, 245);\n"
"border-radius: 18px;\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 8px;"));
        edtInputFormula->setFrameShape(QFrame::NoFrame);
        edtInputFormula->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        edtInputFormula->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        ltGEdit->addWidget(edtInputFormula);

        gviewUnderscore = new QGraphicsView(wdgtGEdit);
        gviewUnderscore->setObjectName(QStringLiteral("gviewUnderscore"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gviewUnderscore->sizePolicy().hasHeightForWidth());
        gviewUnderscore->setSizePolicy(sizePolicy1);
        gviewUnderscore->setMinimumSize(QSize(0, 4));
        gviewUnderscore->setMaximumSize(QSize(16777215, 4));
        gviewUnderscore->setFocusPolicy(Qt::NoFocus);
        gviewUnderscore->setContextMenuPolicy(Qt::NoContextMenu);
        gviewUnderscore->setAcceptDrops(false);
        gviewUnderscore->setAutoFillBackground(false);
        gviewUnderscore->setStyleSheet(QStringLiteral("background-color: rgb(102, 102, 255);"));
        gviewUnderscore->setFrameShape(QFrame::NoFrame);
        gviewUnderscore->setLineWidth(1);
        gviewUnderscore->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gviewUnderscore->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gviewUnderscore->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        QBrush brush(QColor(102, 102, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        gviewUnderscore->setBackgroundBrush(brush);
        gviewUnderscore->setForegroundBrush(brush);
        gviewUnderscore->setSceneRect(QRectF(0, 0, 0, 0));

        ltGEdit->addWidget(gviewUnderscore);


        ltGEB->addLayout(ltGEdit);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 70, 236, 100));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(236, 100));
        label->setPixmap(QPixmap(QString::fromUtf8("../data/images/ChemHelper.jpg")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        ChemHelper->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChemHelper);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 965, 26));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        ChemHelper->setMenuBar(menuBar);

        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(ChemHelper);

        QMetaObject::connectSlotsByName(ChemHelper);
    } // setupUi

    void retranslateUi(QMainWindow *ChemHelper)
    {
        ChemHelper->setWindowTitle(QApplication::translate("ChemHelper", "ChemHelper", nullptr));
        edtInputFormula->setHtml(QApplication::translate("ChemHelper", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\320\260\321\210\320\260 \321\204\320\276\321\200\320\274\321\203\320\273\320\260</p></body></html>", nullptr));
        label->setText(QString());
        menuHelp->setTitle(QApplication::translate("ChemHelper", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChemHelper: public Ui_ChemHelper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEMHELPER_H
