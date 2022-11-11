/********************************************************************************
** Form generated from reading UI file 'txtwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TXTWINDOW_H
#define UI_TXTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TXTWindow
{
public:

    void setupUi(QWidget *TXTWindow)
    {
        if (TXTWindow->objectName().isEmpty())
            TXTWindow->setObjectName("TXTWindow");
        TXTWindow->resize(400, 300);

        retranslateUi(TXTWindow);

        QMetaObject::connectSlotsByName(TXTWindow);
    } // setupUi

    void retranslateUi(QWidget *TXTWindow)
    {
        TXTWindow->setWindowTitle(QCoreApplication::translate("TXTWindow", "TXTWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TXTWindow: public Ui_TXTWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TXTWINDOW_H
