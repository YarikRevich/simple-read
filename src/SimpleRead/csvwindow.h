#ifndef CSVWINDOW_H
#define CSVWINDOW_H

#include "dataview.h"
#include "filewindow.h"

#include <QWidget>
#include <QObject>
#include <QString>
#include <rapidcsv.h>

#define QML_CSVWINDOW "qrc:/csvwindow.qml"

using namespace rapidcsv;

/*!
 * \brief The CSVWindow class used for representation of opened files
 */
class CSVWindow : public QObject, public DataView, public FileWindow
{
private:
    Q_OBJECT

    Document doc;
public:
    explicit CSVWindow(QObject* parent = 0) : QObject(parent){};

    // Event callbacks
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteText(QString) override;

    Q_INVOKABLE QString onReadText() override;

    Q_INVOKABLE void onWriteTable(QHash<QString, void *>) override;

    Q_INVOKABLE QHash<QString, void *> onReadTable() override;

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void setFileName(QString);
};

#endif // CSVWINDOW_H
