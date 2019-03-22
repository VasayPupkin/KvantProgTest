#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

//class TableModel : public QAbstractTableModel
//{
//    Q_OBJECT
//public:

//};

//class TableModel : public QAbstractTableModel
//{
//    Q_OBJECT
//public:
//    TableModel(int nRows, int nColumns, QObject* pobj = nullptr);

//    QVariant data(const QModelIndex& index, int nRole) const;
//    bool setData(const QModelIndex& index,
//                 const QVariant&    value,
//                 int                nRole);
//    int rowCount(const QModelIndex&) const;
//    int columnCount(const QModelIndex&) const;
//    Qt::ItemFlags flags(const QModelIndex& index) const;

//private:
//    int                          nRows_;
//    int                          nColumns_;
//    QHash<QModelIndex, QVariant> hash_;
//};

/*
class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    int rowCount(const QModelIndex & = QModelIndex()) const override
    {
        return 200;
    }

    int columnCount(const QModelIndex & = QModelIndex()) const override
    {
        return 200;
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
//        switch (role) {
//            case Qt::DisplayRole:
//                return QString("%1, %2").arg(index.column()).arg(index.row());
//            default:
//                break;
//        }

//        return QVariant();

        if (!index.isValid()) {
            return QVariant();
        }
        QString str =
           QString("%1,%2").arg(index.row() + 1).arg(index.column() + 1);
        return str;
    }

    QHash<int, QByteArray> roleNames() const override
    {
        return { {Qt::DisplayRole, "display"} };
    }
};
*/

class TableModel : public QAbstractTableModel {
private:
    int                          m_nRows;
    int                          m_nColumns;
    QHash<QModelIndex, QVariant> m_hash;

public:
    TableModel(int nRows, int nColumns, QObject* pobj = 0)
        : QAbstractTableModel(pobj)
        , m_nRows(nRows)
        , m_nColumns(nColumns)
    {
    }

    QVariant data(const QModelIndex& index, int nRole) const
    {
        if (!index.isValid()) {
            return QVariant();
        }
        QString str =
           QString("%1,%2").arg(index.row() + 1).arg(index.column() + 1);
        return (nRole == Qt::DisplayRole || nRole == Qt::EditRole)
               ? m_hash.value(index, QVariant(str))
               : QVariant();
    }

    bool setData(const QModelIndex& index,
                 const QVariant&    value,
                 int                nRole
                )
    {
        if (index.isValid() && nRole == Qt::EditRole) {
            m_hash[index] = value;
            emit dataChanged(index, index);
            return true;
        }
        return false;
    }

    int rowCount(const QModelIndex&) const
    {
        return m_nRows;
    }

    int columnCount(const QModelIndex&) const
    {
        return m_nColumns;
    }

    Qt::ItemFlags flags(const QModelIndex& index) const
    {
        Qt::ItemFlags flags = QAbstractTableModel::flags(index);
        return index.isValid() ? (flags | Qt::ItemIsEditable)
                               : flags;
    }
};


#endif // TABLEMODEL_H
