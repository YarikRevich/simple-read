/********************************************************************************
** Form generated from reading UI file 'pdfwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PDFWINDOW_H
#define UI_PDFWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PDFWindow
{
public:

    void setupUi(QWidget *PDFWindow)
    {
        if (PDFWindow->objectName().isEmpty())
            PDFWindow->setObjectName("PDFWindow");
        PDFWindow->resize(400, 300);

        retranslateUi(PDFWindow);

        QMetaObject::connectSlotsByName(PDFWindow);
    } // setupUi

    void retranslateUi(QWidget *PDFWindow)
    {
        PDFWindow->setWindowTitle(QCoreApplication::translate("PDFWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PDFWindow: public Ui_PDFWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PDFWINDOW_H
