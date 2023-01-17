#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class Backend : public QObject
{
private:
    Q_OBJECT

public:
    explicit Backend(QObject* parent = 0) : QObject(parent){};

    Q_INVOKABLE void rerenderInterface() const;
};

#endif // BACKEND_H
