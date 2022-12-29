#ifndef TXTWINDOW_H
#define TXTWINDOW_H

#include "dataview.h"
#include "filewindow.h"

#include <QWidget>
#include <QObject>
#include <QString>

#define QML_TXTWINDOW "qrc:/txtwindow.qml"

/*!
 * \brief The TXTWindow class used for representation of opened files
 */
class TXTWindow : public QObject, public FileWindow
{
    Q_OBJECT
public:
    explicit TXTWindow(QObject* parent = 0) : QObject(parent){};
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void exec() override;

    Q_INVOKABLE void setFileName(QString);

private:
    DataView *dataView;
};

#endif // TXTWINDOW_H
