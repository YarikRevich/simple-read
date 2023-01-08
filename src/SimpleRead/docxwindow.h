#ifndef DOCXWINDOW_H
#define DOCXWINDOW_H

#include "dataview.h"
#include "filewindow.h"
#include <QObject>
#include <QString>
#include <duckx.hpp>

#define QML_DOCXWINDOW "qrc:/docxwindow.qml"

/*!
 * \class DOCXWindow
 * \brief The DOCXWindow class used for representation of opened files
 */
class DOCXWindow : public QObject, public DataView, public FileWindow
{
private:
    Q_OBJECT

    duckx::Document doc;
public:
    explicit DOCXWindow(QObject* parent = 0) : QObject(parent){};

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

#endif // DOCXWINDOW_H
