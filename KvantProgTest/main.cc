#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "CSVFileReader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CSVFileReader reader;
    reader.fileParse("file:///media/oleg/c2593705-a894-489d-b565-859702b4a4b4/oleg/KirichekOI/GitHubRepository/KvantProgTest/KvantProgTest/TestData.csv");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
