#include "mainwindow.h"
#include "filedialog.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qInfo("'MainWindow' was initialized");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_open_clicked()
{
    qInfo("'Open' button was pressed");


    FileDialog *fileDialog = new FileDialog(this);
    if (!fileDialog->exec()){
        qFatal("'FileDialog' couldn't find a proper processor for selected type of file");
    }
}

void MainWindow::on_pushButton_settings_clicked()
{
    qInfo("'Settings' button was pressed");

    SettingsWindow *settingsWindow = new SettingsWindow();
    settingsWindow->show();
}

