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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChemHelper
{
public:
    QWidget *centralWidget;
    QWidget *GEdit;
    QHBoxLayout *ltGEB;
    QVBoxLayout *ltGEdit;
    QTextEdit *edtInputFormula;
    QGraphicsView *gviewUnderscore;
    QLabel *lblLogo;
    QTableWidget *twSearchResults;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *ChemHelper)
    {
        if (ChemHelper->objectName().isEmpty())
            ChemHelper->setObjectName(QStringLiteral("ChemHelper"));
        ChemHelper->resize(1000, 600);
        ChemHelper->setMinimumSize(QSize(1000, 600));
        ChemHelper->setMaximumSize(QSize(1000, 600));
        ChemHelper->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../data/images/Icon64.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ChemHelper->setWindowIcon(icon);
        ChemHelper->setWindowOpacity(1);
        ChemHelper->setAutoFillBackground(false);
        ChemHelper->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        ChemHelper->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(ChemHelper);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GEdit = new QWidget(centralWidget);
        GEdit->setObjectName(QStringLiteral("GEdit"));
        GEdit->setGeometry(QRect(270, 240, 404, 78));
        ltGEB = new QHBoxLayout(GEdit);
        ltGEB->setSpacing(7);
        ltGEB->setContentsMargins(11, 11, 11, 11);
        ltGEB->setObjectName(QStringLiteral("ltGEB"));
        ltGEB->setSizeConstraint(QLayout::SetMinimumSize);
        ltGEdit = new QVBoxLayout();
        ltGEdit->setSpacing(0);
        ltGEdit->setObjectName(QStringLiteral("ltGEdit"));
        ltGEdit->setSizeConstraint(QLayout::SetMinimumSize);
        edtInputFormula = new QTextEdit(GEdit);
        edtInputFormula->setObjectName(QStringLiteral("edtInputFormula"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edtInputFormula->sizePolicy().hasHeightForWidth());
        edtInputFormula->setSizePolicy(sizePolicy);
        edtInputFormula->setMinimumSize(QSize(380, 50));
        edtInputFormula->setMaximumSize(QSize(380, 50));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(12);
        edtInputFormula->setFont(font);
        edtInputFormula->setStyleSheet(QLatin1String("background-color: rgb(245, 245, 245);\n"
"border-radius: 20px;\n"
"padding-left: 12px;\n"
"padding-right: 10px;\n"
"padding-top: 8px;"));
        edtInputFormula->setFrameShape(QFrame::NoFrame);
        edtInputFormula->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        edtInputFormula->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        ltGEdit->addWidget(edtInputFormula);

        gviewUnderscore = new QGraphicsView(GEdit);
        gviewUnderscore->setObjectName(QStringLiteral("gviewUnderscore"));
        sizePolicy.setHeightForWidth(gviewUnderscore->sizePolicy().hasHeightForWidth());
        gviewUnderscore->setSizePolicy(sizePolicy);
        gviewUnderscore->setMinimumSize(QSize(0, 4));
        gviewUnderscore->setMaximumSize(QSize(380, 4));
        gviewUnderscore->setFocusPolicy(Qt::NoFocus);
        gviewUnderscore->setContextMenuPolicy(Qt::NoContextMenu);
        gviewUnderscore->setAcceptDrops(false);
        gviewUnderscore->setAutoFillBackground(false);
        gviewUnderscore->setStyleSheet(QStringLiteral(""));
        gviewUnderscore->setFrameShape(QFrame::NoFrame);
        gviewUnderscore->setLineWidth(1);
        gviewUnderscore->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gviewUnderscore->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gviewUnderscore->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        gviewUnderscore->setBackgroundBrush(brush);
        QBrush brush1(QColor(85, 255, 127, 255));
        brush1.setStyle(Qt::NoBrush);
        gviewUnderscore->setForegroundBrush(brush1);
        gviewUnderscore->setSceneRect(QRectF(0, 0, 0, 0));

        ltGEdit->addWidget(gviewUnderscore);


        ltGEB->addLayout(ltGEdit);

        lblLogo = new QLabel(centralWidget);
        lblLogo->setObjectName(QStringLiteral("lblLogo"));
        lblLogo->setGeometry(QRect(350, 70, 236, 100));
        sizePolicy.setHeightForWidth(lblLogo->sizePolicy().hasHeightForWidth());
        lblLogo->setSizePolicy(sizePolicy);
        lblLogo->setMinimumSize(QSize(236, 100));
        lblLogo->setPixmap(QPixmap(QString::fromUtf8("../data/images/ChemHelper.jpg")));
        lblLogo->setScaledContents(true);
        lblLogo->setAlignment(Qt::AlignCenter);
        twSearchResults = new QTableWidget(centralWidget);
        if (twSearchResults->columnCount() < 2)
            twSearchResults->setColumnCount(2);
        twSearchResults->setObjectName(QStringLiteral("twSearchResults"));
        twSearchResults->setEnabled(true);
        twSearchResults->setGeometry(QRect(50, 330, 900, 201));
        sizePolicy.setHeightForWidth(twSearchResults->sizePolicy().hasHeightForWidth());
        twSearchResults->setSizePolicy(sizePolicy);
        twSearchResults->setMinimumSize(QSize(0, 0));
        twSearchResults->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(12);
        font1.setUnderline(true);
        twSearchResults->setFont(font1);
        twSearchResults->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        twSearchResults->setMouseTracking(true);
        twSearchResults->setStyleSheet(QLatin1String("background-color: rgb(245, 245, 245);\n"
"border-radius: 20px;\n"
"padding-left: 15px;\n"
"padding-right: 15px;\n"
"padding-top: 8px;\n"
"color: rgb(89, 147, 255)"));
        twSearchResults->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        twSearchResults->setShowGrid(false);
        twSearchResults->setGridStyle(Qt::NoPen);
        twSearchResults->setCornerButtonEnabled(false);
        twSearchResults->setRowCount(0);
        twSearchResults->setColumnCount(2);
        twSearchResults->horizontalHeader()->setVisible(false);
        twSearchResults->verticalHeader()->setVisible(false);
        ChemHelper->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChemHelper);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 26));
        ChemHelper->setMenuBar(menuBar);

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
        lblLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChemHelper: public Ui_ChemHelper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEMHELPER_H
