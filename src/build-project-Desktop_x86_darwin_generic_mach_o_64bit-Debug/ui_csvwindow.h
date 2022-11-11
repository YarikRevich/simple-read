/********************************************************************************
** Form generated from reading UI file 'csvwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSVWINDOW_H
#define UI_CSVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSVWindow
{
public:

    void setupUi(QWidget *CSVWindow)
    {
        if (CSVWindow->objectName().isEmpty())
            CSVWindow->setObjectName("CSVWindow");
        CSVWindow->resize(400, 300);

        retranslateUi(CSVWindow);

        QMetaObject::connectSlotsByName(CSVWindow);
    } // setupUi

    void retranslateUi(QWidget *CSVWindow)
    {
        CSVWindow->setWindowTitle(QCoreApplication::translate("CSVWindow", "CSVWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSVWindow: public Ui_CSVWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSVWINDOW_H
