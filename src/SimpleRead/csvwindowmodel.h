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
    CSVWindow* csvWindow;
public:
    explicit CSVWindowModel(CSVWindow* csvWindow) : csvWindow{csvWindow}{}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // CSVWINDOWMODEL_H
