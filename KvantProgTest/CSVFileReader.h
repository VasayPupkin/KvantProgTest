#ifndef CSVFILEREADER_H
#define CSVFILEREADER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QList>
#include <QStringList>

class CSVFileReader : public QObject
{
    Q_OBJECT
public:
    explicit CSVFileReader(QObject *parent = nullptr);

private:
    QString convertFileUrl(const QString &fileUrl);
    bool openCSVFile(const QString &filePath);
signals:
    void sendInfoMsg(QString msg);

public slots:
    void fileParse(const QString &fileUrl);

private:
    QFile csvFile;
    const QString separator{";"};
    QList<QStringList> dataList;
};

#endif // CSVFILEREADER_H
