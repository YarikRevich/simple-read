#ifndef DOCXWINDOW_H
#define DOCXWINDOW_H

#include "dataview.h"
#include "qmlwindow.h"
#include "statistics.h"
#include "textwindowread.h"

#include <QObject>
#include <QString>
#include <duckx.hpp>

#define QML_DOCXWINDOW "qrc:/docxwindow.qml"

/*!
 * \class DOCXWindow
 * \brief The DOCXWindow class used for representation of opened files
 */
class DOCXWindow : public QObject, public TextWindowRead, public QMLWindow, public Statistics
{
private:
    Q_OBJECT

    std::string file_in_buffer;
    duckx::Document doc;
public:
    Q_INVOKABLE void setFileName(QString);

    // Custom overrides
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onClose();

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE QString onReadText(int start, int end) override;

    Q_INVOKABLE int getContentSize() override;

    Q_INVOKABLE Statistics* getStatistics();
};

#endif // DOCXWINDOW_H
