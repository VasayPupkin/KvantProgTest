#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <QPointer>

#include "QMLWidget.h"
#include "CSVFileReader.h"
#include "TableModel.h"

#include "TableViewWindow.h"

class Mediator : public QObject
{
    Q_OBJECT
public:
    explicit Mediator(QObject *parent = nullptr);

    bool show();

private:
    void createObjects();
    void connectObjects();

signals:
//    void setTableViewVisible(TableModel tableModel);

public slots:
    void createTableModel(int numberOfRows, int numberOfColumns);

private:
    QPointer<QMLWidget> qmlWdgt;
    QPointer<CSVFileReader> csvFileReader;
    QPointer<TableModel> tableModel;

    QPointer<TableViewWindow> tableViewWindow;
};

#endif // MEDIATOR_H
