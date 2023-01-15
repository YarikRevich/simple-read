#ifndef QMLWINDOW_H
#define QMLWINDOW_H

#include <QObject>
#include <QQuickWidget>
#include "basewindow.h"

class QMLWindow : public BaseWindow
{
protected:
    QString fileName;

public:
    /*!
     * \brief onOpen a listener for open event
     * \param qmlFilePath a path to a qml file
     */
    void onOpen(const char * qmlFilePath) const override;

    void setFileName(QString);
};

#endif // QMLWINDOW_H
