#ifndef QMLWIDGET_H
#define QMLWIDGET_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QPointer>

class QMLWidget : public QObject
{
    Q_OBJECT
public:
    explicit QMLWidget(QObject *parent = nullptr);

signals:

public slots:
    QPointer<QQmlApplicationEngine> getEngine() const { return engine; }

private:
    QPointer<QQmlApplicationEngine> engine;
};

#endif // QMLWIDGET_H
