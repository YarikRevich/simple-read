#ifndef QMLTYPEREGISTRATOR_H
#define QMLTYPEREGISTRATOR_H

#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

/*!
 * \brief The QMLTypeRegistrator class is used for QML context property registration
 */
class QMLTypeRegistrator
{
public:
    QMLTypeRegistrator(QQmlApplicationEngine* engine) : engine{engine}{};

    /*!
     * \brief exec runs a registration process of QML context property
     */
    void exec() const;
private:
    QQmlApplicationEngine* engine;
};

#endif // QMLTYPEREGISTRATOR_H
