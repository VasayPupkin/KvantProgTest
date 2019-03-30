#include "TableModel.h"

TableModel::TableModel(QObject *parent):
    QAbstractTableModel(parent)
{
}

void TableModel::setDataList(QList<QStringList> dataList)
{
    dataList_ = dataList;
//    int row = dataList_.size();
//    int column = dataList_.first().size();
//    for (auto i = 0;i < row; ++i) {
//        for (auto j = 0; j < column; ++j) {
//            setData(index(i,j),dataList_.at(i).at(j),Qt::EditRole);
//        }
//    }
    emit dataChanged(index(0,0),
                     index(dataList_.size()-1,dataList_.first().size() - 1),
                     {UserIdRole,UserNameRole,UserPhoneRole});
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dataList_.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (rowCount(parent) > 0)
        return dataList_.first().size();
    return 0;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::TextAlignmentRole)
        return QVariant(Qt::AlignCenter);
//    else if (role == Qt::DisplayRole) {
//        if (index.row() >= rowCount(index) || index.row() < 0) {
//            return  QVariant();
//        }
//        if (index.column() >= columnCount(index) || index.column() < 0) {
//            return  QVariant();
//        }
//        return QVariant(dataList_.at(index.row()).at(index.column()));
//    }
    if (role == UserIdRole) {
        return QVariant(dataList_.at(index.row()).at(0));
    }
    if (role == UserNameRole) {
        return QVariant(dataList_.at(index.row()).at(1));
    }
    if (role == UserPhoneRole) {
        return QVariant(dataList_.at(index.row()).at(2));
    }
    return  QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal) {
        QStringList headerList{"USER_ID","USER_NAME","PHONE_NUMBER"};
        if (section < headerList.size())
            return headerList[section];
    }
    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    return flags;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();
        int column = index.column();
        dataList_[row][column] = value.toString();
        emit dataChanged(index,index,{role/*,UserIdRole,UserNameRole,UserPhoneRole*/});
        return true;
    }
    return  false;
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[UserIdRole] = "user_id";
    roles[UserNameRole] = "user_name";
    roles[UserPhoneRole] = "user_phone";
    return roles;
}
