#ifndef QMLWINDOW_H
#define QMLWINDOW_H

#include <QObject>
#include <QQuickWidget>

class QMLWindow
{
public:

    /*!
     * \brief onOpen a listener for open event
     * \param qmlFilePath a path to a qml file
     */
    void onOpen(const char * qmlFilePath);

//    void loadContextProperties(QQmlContext* context);
};

#endif // QMLWINDOW_H
