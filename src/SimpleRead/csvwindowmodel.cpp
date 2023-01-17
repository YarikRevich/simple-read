#include "csvwindowmodel.h"

#include <QModelIndex>

int CSVWindowModel::rowCount(const QModelIndex &parent) const {
    QVariantMap table = this->csvWindow->onReadTable();
    return table.value(table.keys()[0]).toList().length() + 1;
}

int CSVWindowModel::columnCount(const QModelIndex &parent) const {
    return this->csvWindow->onReadTable().keys().length();
}

QVariant CSVWindowModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    QVariantMap table = this->csvWindow->onReadTable();

    if (index.row() == 0){
        return table.keys()[index.column()];
    }

    return  table.value(table.keys()[index.column()]).toList()[index.row() - 1].toString();
}

bool CSVWindowModel::setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if (index.isValid()) {
            QVariantMap table = this->csvWindow->onReadTable();
            QList<QString> values = table[table.keys()[index.row()]].toStringList();

            values[index.column()-1] = value.toString();
            table[table.keys()[index.row()]] = values;

            this->csvWindow->onWriteTable(table);

            return true;
        }
        return false;
    }

Qt::ItemFlags CSVWindowModel::flags(const QModelIndex &index) const{
    return Qt::ItemIsEditable;
};

QModelIndex CSVWindowModel::index(int row, int column, const QModelIndex &parent) const{
    return createIndex(row, column);
};

QVariant CSVWindowModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    QVariantMap table = this->csvWindow->onReadTable();

    return table.keys()[section];
}
