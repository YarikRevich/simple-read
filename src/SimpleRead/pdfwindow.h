#ifndef PDFWINDOW_H
#define PDFWINDOW_H

#include "dataview.h"
#include "textwindowread.h"
#include "statistics.h"
#include "qmlwindow.h"

#include <QWidget>
#include <QObject>
#include <QString>

#define QML_PDFWINDOW "qrc:/pdfwindow.qml"

/*!
 * \brief The PDFWindow class used for representation of opened files
 */
class PDFWindow : public QObject, public TextWindowRead, public QMLWindow, public Statistics
{
private:
    Q_OBJECT

    std::string file_in_buffer;
public:
    explicit PDFWindow(QObject* parent = 0) : QObject(parent){}

    Q_INVOKABLE void setFileName(QString);

    // Event callbacks
    Q_INVOKABLE void onOpen();

    Q_INVOKABLE void onClose();

    Q_INVOKABLE void onInit() override;

    Q_INVOKABLE QString onReadText(int start, int end) override;

    Q_INVOKABLE int getContentSize() override;

    Q_INVOKABLE Statistics* getStatistics();
};

#endif // PDFWINDOW_H
