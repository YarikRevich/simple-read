#ifndef CSVWINDOW_H
#define CSVWINDOW_H

#include "dataview.h"
#include "filewindow.h"

#include <QWidget>
#include <QObject>
#include <QString>
#include <QList>
#include <rapidcsv.h>
#include "qmlwindow.h"
#include "tablewindow.h"

#define QML_CSVWINDOW "qrc:/csvwindow.qml"

using namespace rapidcsv;

/*!
 * \brief The CSVWindow class used for representation of opened files
 */
class CSVWindow : public QObject, public TableWindow, public QMLWindow
{
private:
    Q_OBJECT

    QVariantMap file_out_buffer;
    QVariantMap file_in_buffer;

    Document doc;
public:
    explicit CSVWindow(QObject* parent = 0) : QObject(parent){};

    // Custom overrides
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void setFileName(QString);


    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteTable(QVariantMap) override;

    Q_INVOKABLE QVariantMap onReadTable() const override;
};

#endif // CSVWINDOW_H
