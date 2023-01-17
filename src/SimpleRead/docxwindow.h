#ifndef DOCXWINDOW_H
#define DOCXWINDOW_H

#include "dataview.h"
#include "qmlwindow.h"
#include <QObject>
#include <QString>
#include <duckx.hpp>
#include "statistics.h"
#include "textwindow.h"

#define QML_DOCXWINDOW "qrc:/docxwindow.qml"

/*!
 * \class DOCXWindow
 * \brief The DOCXWindow class used for representation of opened files
 */
class DOCXWindow : public QObject, public TextWindow, public QMLWindow, public Statistics
{
private:
    Q_OBJECT

    std::string file_in_buffer;
    duckx::Document doc;
public:
    explicit DOCXWindow(QObject* parent = 0) : QObject(parent){}

    Q_INVOKABLE void setFileName(QString);

    // Custom overrides
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onClose();

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteText(QString, int start, int end) override;

    Q_INVOKABLE QString onReadText(int start, int end) override;

    Q_INVOKABLE int getContentSize() override;

    Q_INVOKABLE Statistics* getStatistics();
};

#endif // DOCXWINDOW_H
