#ifndef PDFWINDOW_H
#define PDFWINDOW_H

#include "dataview.h"
#include "filewindow.h"

#include <QWidget>
#include <QObject>
#include <QString>

#define QML_PDFWINDOW "qrc:/pdfwindow.qml"

/*!
 * \brief The PDFWindow class used for representation of opened files
 */
class PDFWindow : public QObject, public DataView, public FileWindow
{
    Q_OBJECT
public:
    explicit PDFWindow(QObject* parent = 0) : QObject(parent){};

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

#endif // PDFWINDOW_H
