#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <QPointer>

#include "QMLWidget.h"
#include "CSVFileReader.h"
#include "TableModel.h"

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
    void setTableViewVisible();

public slots:
    void createTableModel();

private:
    QPointer<QMLWidget> qmlWdgt;
    QPointer<CSVFileReader> csvFileReader;
    QPointer<TableModel> tableModel;
};

#endif // MEDIATOR_H
