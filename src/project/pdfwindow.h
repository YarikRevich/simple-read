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
class PDFWindow : public QObject, public FileWindow
{
    Q_OBJECT
public:
    explicit PDFWindow(QObject* parent = 0) : QObject(parent){};
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void exec() override;

    Q_INVOKABLE void setFileName(QString);

private:
    DataView *dataView;
};

#endif // PDFWINDOW_H
