#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QList>
#include <QStringList>
#include <QHash>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_ENUMS(Roles)
public:
    enum Roles {
        UserIdRole = Qt::UserRole + 1,
        UserNameRole,
        UserPhoneRole
    };

    TableModel(QObject *parent = nullptr);

    void setDataList(QList<QStringList> dataList);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<QStringList> dataList_;
};

#endif // TABLEMODEL_H
