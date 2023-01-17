#ifndef CSVWINDOWMODEL_H
#define CSVWINDOWMODEL_H

#include "csvwindow.h"
#include <QAbstractTableModel>




class CSVWindowModel : public QAbstractTableModel
{
private:
    CSVWindow* csvWindow;
public:
    explicit CSVWindowModel(CSVWindow* csvWindow) : csvWindow{csvWindow}{}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        QVariantMap table = this->csvWindow->onReadTable();
        return table.value(table.keys()[0]).toList().length() + 1;
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return this->csvWindow->onReadTable().keys().length();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || role != Qt::DisplayRole)
            return QVariant();

        QVariantMap table = this->csvWindow->onReadTable();

        if (index.row() == 0){
            return table.keys()[index.column()];
        }

        return  table.value(table.keys()[index.column()]).toList()[index.row() - 1];
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override
        {
            if (index.isValid() && role == Qt::EditRole) {
                qInfo() << index.row() << index.column();

                QVariantMap table = this->csvWindow->onReadTable();
                QList<QVariant> values = table[table.keys()[index.row()]].toList();
                values[index.column()] = value;
                table[table.keys()[index.row()]] = values;

                this->csvWindow->onWriteTable(table);
                emit dataChanged(index, index);
                return true;
            }
            return false;
        }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
            return QVariant();

        QVariantMap table = this->csvWindow->onReadTable();

        return table.keys()[section];
    }
};


///*!
// * \brief The CSVWindowModel class is used for model representation of CSVWindow
// */
//class CSVWindowModel : public QAbstractTableModel
//{
//private:
//    Q_OBJECT

//public:
//    CSVWindowModel(CSVWindow *csvwindow);
////    explicit CSVWindowModel(QObject* parent = nullptr) {};

//    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const override;

//    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const override;

//    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

//    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const override;

//    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override;

//    Q_INVOKABLE QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
//};

#endif // CSVWINDOWMODEL_H
