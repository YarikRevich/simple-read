#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./docxwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:

    MainWindow *mainWindow;
    DOCXWindow *docxWindow = new DOCXWindow();

};
#endif // MAINWINDOW_H
