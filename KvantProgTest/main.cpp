#include <QGuiApplication>
#include "Mediator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Mediator mediator;
    if (!mediator.show())
        return -1;

    return app.exec();
}
