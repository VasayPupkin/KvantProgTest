#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
public:
    TableModel(int nRows, int nColumns, QObject* pobj = nullptr);

    QVariant data(const QModelIndex& index, int nRole) const;
    bool setData(const QModelIndex& index,
                 const QVariant&    value,
                 int                nRole);
    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;

private:
    int                          nRows_;
    int                          nColumns_;
    QHash<QModelIndex, QVariant> hash_;
};

#endif // TABLEMODEL_H
