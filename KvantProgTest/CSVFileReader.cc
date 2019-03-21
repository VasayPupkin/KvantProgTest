#include <QTextStream>
#include "CSVFileReader.h"

CSVFileReader::CSVFileReader(QObject *parent) : QObject(parent)
{

}

void CSVFileReader::convertFileUrl(QString &fileUrl)
{
//file:///media/oleg/c2593705-a894-489d-b565-859702b4a4b4/oleg/KirichekOI/GitHubRepository/KvantProgTest/KvantProgTest/TestData.csv
    fileUrl = fileUrl.replace("file://","");
}

bool CSVFileReader::openCSVFile(const QString &filePath)
{
    csvFile.setFileName(filePath);
    return csvFile.open(QIODevice::ReadOnly | QIODevice::Text);
}

void CSVFileReader::fileParse(const QString &fileUrl)
{
    QString filePath = fileUrl;
    convertFileUrl(filePath);
    if(openCSVFile(filePath)){
        dataList.clear();
        QString tmpStr;
        QStringList strList;
        QTextStream stream(&csvFile);
        while (!stream.atEnd()) {
            tmpStr = stream.readLine();
            strList = tmpStr.split(separator);
            strList.pop_back();
            dataList.push_back(strList);
        }
        csvFile.close();
        emit fileIsParsed(getNumberOfRows(), getNumberOfColumns());
    }
    else
        emit sendInfoMsg(fileUrl + " was not opened.");
}
