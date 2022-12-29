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
class CSVWindow : public QObject, public FileWindow
{
    Q_OBJECT
public:
    explicit CSVWindow(QObject* parent = 0) : QObject(parent){};
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void exec() override;

    Q_INVOKABLE void setFileName(QString);

private:
    DataView *dataView;
};

#endif // CSVWINDOW_H
