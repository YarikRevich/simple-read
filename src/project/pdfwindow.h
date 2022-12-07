#ifndef PDFWINDOW_H
#define PDFWINDOW_H

#include "filewindow.h"

#include <QWidget>

namespace Ui {
class PDFWindow;
}

class PDFWindow : public FileWindow
{
    Q_OBJECT

public:
    explicit PDFWindow(QString fileName, QWidget *parent = nullptr);
    ~PDFWindow();

private:
    Ui::PDFWindow *ui;

    QString fileName;
};

#endif // PDFWINDOW_H
