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
    void fileIsParsed(int numberOfRows, int numberOfColumns);

public slots:
    void fileParse(const QString &fileUrl);
    int getNumberOfColumns() const { return (dataList.isEmpty() ? 0 : dataList.at(0).size()); }
    int getNumberOfRows() const { return dataList.size(); }

private:
    QFile csvFile;
    const QString separator{";"};
    QList<QStringList> dataList;
};

#endif // CSVFILEREADER_H
