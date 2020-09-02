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
    connect(csvFileReader.data(),SIGNAL(fileIsParsed()),
            SLOT(createTableModel()));
}

void Mediator::createTableModel()
{
    if (!tableModel.isNull())
        tableModel.clear();
    tableModel = new TableModel(this);
    tableModel.data()->setDataList(csvFileReader.data()->getDataList());
    qmlWdgt.data()->getEngine().data()->rootContext()->setContextProperty("TableModel", tableModel.data());

}
