#ifndef CSVWINDOWMODEL_H
#define CSVWINDOWMODEL_H

#include "csvwindow.h"
#include <QAbstractTableModel>


/*!
 * \brief The CSVWindowModel class is used for model representation of CSVWindow
 */
class CSVWindowModel : public QAbstractTableModel
{
private:
    Q_OBJECT

public:
    CSVWindowModel(CSVWindow *csvwindow);

    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames() const override;
};

#endif // CSVWINDOWMODEL_H
