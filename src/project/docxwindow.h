#ifndef DOCXWINDOW_H
#define DOCXWINDOW_H

#include "dataview.h"
#include "filewindow.h"
#include <QObject>
#include <QString>

#define QML_DOCXWINDOW "qrc:/docxwindow.qml"

/*!
 * \brief The DOCXWindow class used for representation of opened files
 */
class DOCXWindow : public QObject, public FileWindow
{
    Q_OBJECT
public:
    explicit DOCXWindow(QObject* parent = 0) : QObject(parent){};
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void exec() override;

    Q_INVOKABLE void setFileName(QString);

private:
    DataView *dataView;
};

#endif // DOCXWINDOW_H
