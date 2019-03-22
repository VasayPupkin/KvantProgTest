//#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>

#include "Mediator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

//    qmlRegisterType<TableModel>("TableModel", 1, 0, "TableModel");
//    CSVFileReader reader;
//    reader.fileParse("file:///media/oleg/c2593705-a894-489d-b565-859702b4a4b4/oleg/KirichekOI/GitHubRepository/KvantProgTest/KvantProgTest/TestData.csv");

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    Mediator mediator;
    if (!mediator.show())
        return -1;

    return app.exec();
}
