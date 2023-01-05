#ifndef CSVWINDOW_H
#define CSVWINDOW_H

#include "dataview.h"
#include "filewindow.h"

#include <QWidget>
#include <QObject>
#include <QString>

#define QML_CSVWINDOW "qrc:/csvwindow.qml"

/*!
 * \brief The CSVWindow class used for representation of opened files
 */
class CSVWindow : public QObject, public DataView, public FileWindow
{
    Q_OBJECT
public:
    explicit CSVWindow(QObject* parent = 0) : QObject(parent){};

    // Event callbacks
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteText(QString) override;

    Q_INVOKABLE QString onRead() override;

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void setFileName(QString);
};

#endif // CSVWINDOW_H
