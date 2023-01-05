#ifndef TXTWINDOW_H
#define TXTWINDOW_H

#include "dataview.h"
#include "filewindow.h"

#include <QWidget>
#include <QObject>
#include <QString>
#include <fstream>

#define QML_TXTWINDOW "qrc:/txtwindow.qml"

/*!
 * \brief The TXTWindow class used for representation of opened files
 */
class TXTWindow : public QObject, public DataView, public FileWindow
{
    Q_OBJECT

    std::ifstream file;
public:
    explicit TXTWindow(QObject* parent = 0) : QObject(parent){};

    // Event callbacks
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteText(QString) override;

    Q_INVOKABLE QString onRead() override;

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void setFileName(QString);
};

#endif // TXTWINDOW_H
