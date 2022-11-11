#ifndef CSVWINDOW_H
#define CSVWINDOW_H

#include <QWidget>

namespace Ui {
class CSVWindow;
}

class CSVWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CSVWindow(QString fileName, QWidget *parent = nullptr);
    ~CSVWindow();

private:
    Ui::CSVWindow *ui;

    QString fileName;
};

#endif // CSVWINDOW_H
