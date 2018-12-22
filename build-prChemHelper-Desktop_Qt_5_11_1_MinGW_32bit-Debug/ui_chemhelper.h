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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChemHelper
{
public:
    QWidget *centralWidget;
    QFrame *lnDownloadStatus;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *ltGoogleEdit;
    QVBoxLayout *verticalLayout;
    QLineEdit *edtInputFormula;
    QLabel *label_2;
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
        lnDownloadStatus = new QFrame(centralWidget);
        lnDownloadStatus->setObjectName(QStringLiteral("lnDownloadStatus"));
        lnDownloadStatus->setGeometry(QRect(320, 390, 151, 16));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        lnDownloadStatus->setPalette(palette);
        lnDownloadStatus->setFrameShape(QFrame::HLine);
        lnDownloadStatus->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(680, 240, 121, 121));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setPixmap(QPixmap(QString::fromUtf8("../data/images/SearchButton.jpg")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 140, 391, 181));
        ltGoogleEdit = new QHBoxLayout(widget);
        ltGoogleEdit->setSpacing(6);
        ltGoogleEdit->setContentsMargins(11, 11, 11, 11);
        ltGoogleEdit->setObjectName(QStringLiteral("ltGoogleEdit"));
        ltGoogleEdit->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        edtInputFormula = new QLineEdit(widget);
        edtInputFormula->setObjectName(QStringLiteral("edtInputFormula"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(edtInputFormula->sizePolicy().hasHeightForWidth());
        edtInputFormula->setSizePolicy(sizePolicy1);
        edtInputFormula->setMinimumSize(QSize(5, 30));
        edtInputFormula->setCursor(QCursor(Qt::IBeamCursor));
        edtInputFormula->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(edtInputFormula);


        ltGoogleEdit->addLayout(verticalLayout);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        ltGoogleEdit->addWidget(label_2);

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
        label->setText(QString());
        edtInputFormula->setText(QApplication::translate("ChemHelper", "\320\222\320\260\321\210\320\260 \321\204\320\276\321\200\320\274\321\203\320\273\320\260", nullptr));
        label_2->setText(QApplication::translate("ChemHelper", "TextLabel", nullptr));
        menuHelp->setTitle(QApplication::translate("ChemHelper", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChemHelper: public Ui_ChemHelper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEMHELPER_H
