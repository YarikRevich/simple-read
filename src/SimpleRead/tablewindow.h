#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QString>
#include <QList>
#include <QVariantMap>

class TableWindow
{
public:
    virtual void onWriteTable(QVariantMap) = 0;

    virtual QVariantMap onReadTable() const = 0;
};

#endif // TABLEWINDOW_H
