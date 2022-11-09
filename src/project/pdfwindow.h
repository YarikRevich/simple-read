#ifndef PDFWINDOW_H
#define PDFWINDOW_H

#include <QWidget>

namespace Ui {
class PDFWindow;
}

class PDFWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PDFWindow(QWidget *parent = nullptr);
    ~PDFWindow();

private:
    Ui::PDFWindow *ui;
};

#endif // PDFWINDOW_H
