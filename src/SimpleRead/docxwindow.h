#ifndef DOCXWINDOW_H
#define DOCXWINDOW_H

#include "dataview.h"
#include "qmlwindow.h"
#include <QObject>
#include <QString>
#include <duckx.hpp>
#include "textwindow.h"

#define QML_DOCXWINDOW "qrc:/docxwindow.qml"

/*!
 * \class DOCXWindow
 * \brief The DOCXWindow class used for representation of opened files
 */
class DOCXWindow : public QObject, public TextWindow, public QMLWindow
{
private:
    Q_OBJECT

    duckx::Document doc;
public:
    explicit DOCXWindow(QObject* parent = 0) : QObject(parent){};

    // Custom overrides
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void setFileName(QString);


    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteText(QString, int start, int end) override;

    Q_INVOKABLE QString onReadText(int start, int end) override;

    Q_INVOKABLE int getContentSize() override;
};

#endif // DOCXWINDOW_H
