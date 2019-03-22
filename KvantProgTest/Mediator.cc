#include <QQmlContext>
#include "Mediator.h"

Mediator::Mediator(QObject *parent) : QObject(parent)
{
    createObjects();
    connectObjects();
}

bool Mediator::show()
{
    return !qmlWdgt.data()->getEngine().data()->rootObjects().isEmpty();
}

void Mediator::createObjects()
{
    qmlWdgt = new QMLWidget();
    csvFileReader = new CSVFileReader();
}

void Mediator::connectObjects()
{
    QQmlApplicationEngine *engine = qmlWdgt.data()->getEngine();
    QObject *engineObj = engine->rootObjects().first();
    connect(engineObj, SIGNAL(setFileName(QString)),
            csvFileReader.data(), SLOT(fileParse(QString)));

    connect(csvFileReader.data(), SIGNAL(sendInfoMsg(QVariant)),
            engineObj, SLOT(setTextFieldText(QVariant)));
    connect(csvFileReader.data(),SIGNAL(fileIsParsed(int,int)),
            SLOT(createTableModel(int,int)));
}

void Mediator::createTableModel(int numberOfRows, int numberOfColumns)
{
//    tableModel = new TableModel();
////    qmlWdgt.data()->getEngine().data()->rootContext()->setContextProperty("TableModel", tableModel.data());
//    for(int i = 0 ; i < 5 ;++i){
//        for (int j = 0; j < 5; ++j) {
//            tableModel.data()->setData(tableModel.data()->index(0,0),"MFK!!!");
//        }
//    }
//    emit setTableViewVisible(*(tableModel.data()));
    tableModel = new TableModel(10,10);
    tableViewWindow = new TableViewWindow();
    tableViewWindow.data()->getTableView()->setModel(tableModel.data());
    for(int i = 0 ; i < 5 ;++i){
        for (int j = 0; j < 5; ++j) {
            tableModel.data()->setData(tableModel.data()->index(0,0),"MFK!!!",0);
        }
    }
    tableViewWindow.data()->show();
}
