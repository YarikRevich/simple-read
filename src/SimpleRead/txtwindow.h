#ifndef TXTWINDOW_H
#define TXTWINDOW_H

#include "dataview.h"
#include "filewindow.h"
#include "textwindow.h"
#include "statistics.h"
#include <sstream>

#include <QWidget>
#include <QObject>
#include <QString>
#include <fstream>

#define QML_TXTWINDOW "qrc:/txtwindow.qml"

/*!
 * \brief The TXTWindow class used for representation of opened files
 */
class TXTWindow : public QObject, public TextWindow, public QMLWindow, public Statistics
{
    Q_OBJECT

    std::stringstream file_out_buffer;
    std::stringstream file_in_buffer;
public:
    explicit TXTWindow(QObject* parent = 0) : QObject(parent){}

    // Event callbacks
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onClose();

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE void onSave() override;

    Q_INVOKABLE void onWriteText(QString, int start, int end) override;

    Q_INVOKABLE QString onReadText(int start, int end) override;

    Q_INVOKABLE int getContentSize() override;

    Q_INVOKABLE void setFileName(QString);

    Q_INVOKABLE Statistics* getStatistics();
};

#endif // TXTWINDOW_H
