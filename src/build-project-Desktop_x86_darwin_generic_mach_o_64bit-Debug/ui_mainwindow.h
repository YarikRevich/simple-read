/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_open;
    QPushButton *pushButton_settings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 150);
        MainWindow->setMinimumSize(QSize(500, 150));
        MainWindow->setMaximumSize(QSize(500, 150));
        MainWindow->setMouseTracking(true);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 126);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(500, 99));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(100, 10, 301, 91));
        horizontalLayout = new QHBoxLayout(gridLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_open = new QPushButton(gridLayoutWidget);
        pushButton_open->setObjectName("pushButton_open");
        pushButton_open->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_open);

        pushButton_settings = new QPushButton(gridLayoutWidget);
        pushButton_settings->setObjectName("pushButton_settings");
        pushButton_settings->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_settings->setStyleSheet(QString::fromUtf8("color: rgb(247, 255, 254);\n"
"background-color: rgb(255, 255, 255);"));
        pushButton_settings->setLocale(QLocale(QLocale::English, QLocale::Europe));

        horizontalLayout->addWidget(pushButton_settings);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        pushButton_settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
