#include "filewindow.h"
#include <QApplication>
#include <QScreen>
#include <QGuiApplication>
#include <QRect>

FileWindow::FileWindow(QWidget *parent) : QWidget(parent)
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QSize screenSize = screen->size();

    const double baseWidth = screenSize.width() - (20 * screenSize.width() / 100);
    const double baseHeight = screenSize.height() - (20 * screenSize.height() / 100);

    this->setMinimumSize(QSize(baseWidth, baseHeight));
}
