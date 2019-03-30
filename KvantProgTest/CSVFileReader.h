#ifndef CSVFILEREADER_H
#define CSVFILEREADER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QList>
#include <QStringList>
#include <QVariant>

class CSVFileReader : public QObject
{
    Q_OBJECT
public:
    explicit CSVFileReader(QObject *parent = nullptr);

private:
    void convertFileUrl(QString &fileUrl);
    bool openCSVFile(const QString &filePath);
signals:
    void sendInfoMsg(QVariant msg);
    void fileIsParsed();

public slots:
    void fileParse(const QString &fileUrl);
    QList<QStringList> getDataList() const { return dataList_; }

private:
    QFile csvFile_;
    const QString separator_{";"};
    QList<QStringList> dataList_;
};

#endif // CSVFILEREADER_H
