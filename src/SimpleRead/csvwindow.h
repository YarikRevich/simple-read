#ifndef CSVWINDOW_H
#define CSVWINDOW_H

#include "dataview.h"
#include "filewindow.h"
#include "statistics.h"

#include <QWidget>
#include <QObject>
#include <QString>
#include <QList>
#include <rapidcsv.h>
#include "qmlwindow.h"
#include "tablewindow.h"
#include <QAbstractTableModel>

#define QML_CSVWINDOW "qrc:/csvwindow.qml"

using namespace rapidcsv;

/*!
 * \brief The CSVWindow class used for representation of CSV files
 */
class CSVWindow : public QObject, public TableWindow, public QMLWindow, public Statistics
{
private:
    Q_OBJECT

    QVariantMap file_out_buffer;
    QVariantMap file_in_buffer;

    Document doc;
public:
    explicit CSVWindow(QObject* parent = 0) {}

    Q_INVOKABLE void setFileName(QString);

    // Custom overrides
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onClose();

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteTable(QVariantMap) override;

    Q_INVOKABLE QVariantMap onReadTable() const override;

    Q_INVOKABLE Statistics* getStatistics();
};

#endif // CSVWINDOW_H
