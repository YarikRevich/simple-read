#ifndef PDFWINDOW_H
#define PDFWINDOW_H

#include "dataview.h"
#include "filewindow.h"
#include "textwindow.h"

#include <QWidget>
#include <QObject>
#include <QString>

#define QML_PDFWINDOW "qrc:/pdfwindow.qml"

/*!
 * \brief The PDFWindow class used for representation of opened files
 */
class PDFWindow : public QObject, public TextWindow, public QMLWindow
{
private:
    Q_OBJECT

    std::string file_in_buffer;
public:
    explicit PDFWindow(QObject* parent = 0) : QObject(parent){};

    // Event callbacks
    Q_INVOKABLE void onOpen();


    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteText(QString, int start, int end) override;

    Q_INVOKABLE QString onReadText(int start, int end) override;

    Q_INVOKABLE int getContentSize() override;


    Q_INVOKABLE void setFileName(QString);
};

#endif // PDFWINDOW_H
