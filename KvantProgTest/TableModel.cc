#include "TableModel.h"

TableModel::TableModel(int nRows, int nColumns, QObject *pobj):
    QAbstractTableModel (pobj),
    nRows_(nRows),
    nColumns_(nColumns)
{
}

QVariant TableModel::data(const QModelIndex &index, int nRole) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    QString str =
            QString("%1,%2").arg(index.row() + 1).arg(index.column() + 1);
    return (nRole == Qt::DisplayRole || nRole == Qt::EditRole)
            ? hash_.value(index, QVariant(str))
            : QVariant();
}

bool TableModel::setData(const QModelIndex& index,
                         const QVariant&    value,
                         int                nRole)
{
    if (index.isValid() && nRole == Qt::EditRole) {
        hash_[index] = value;
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

int TableModel::rowCount(const QModelIndex &) const
{
    return nRows_;
}

int TableModel::columnCount(const QModelIndex &) const
{
    return nColumns_;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    return index.isValid() ? (flags | Qt::ItemIsEditable)
                           : flags;
}
