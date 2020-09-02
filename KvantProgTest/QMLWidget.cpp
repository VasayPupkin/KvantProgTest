#include "QMLWidget.h"

QMLWidget::QMLWidget(QObject *parent) : QObject(parent)
{
    engine = new QQmlApplicationEngine();
    engine.data()->load(QUrl(QStringLiteral("qrc:/main.qml")));
}
