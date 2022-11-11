/********************************************************************************
** Form generated from reading UI file 'docxwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCXWINDOW_H
#define UI_DOCXWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DOCXWindow
{
public:

    void setupUi(QWidget *DOCXWindow)
    {
        if (DOCXWindow->objectName().isEmpty())
            DOCXWindow->setObjectName("DOCXWindow");
        DOCXWindow->resize(400, 300);

        retranslateUi(DOCXWindow);

        QMetaObject::connectSlotsByName(DOCXWindow);
    } // setupUi

    void retranslateUi(QWidget *DOCXWindow)
    {
        DOCXWindow->setWindowTitle(QCoreApplication::translate("DOCXWindow", "DOCXWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DOCXWindow: public Ui_DOCXWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCXWINDOW_H
