#include <QTextStream>
#include "CSVFileReader.h"

CSVFileReader::CSVFileReader(QObject *parent) : QObject(parent)
{

}

void CSVFileReader::convertFileUrl(QString &fileUrl)
{
    fileUrl = fileUrl.replace("file://","");
}

bool CSVFileReader::openCSVFile(const QString &filePath)
{
    csvFile_.setFileName(filePath);
    return csvFile_.open(QIODevice::ReadOnly | QIODevice::Text);
}

void CSVFileReader::fileParse(const QString &fileUrl)
{
    QString filePath = fileUrl;
    convertFileUrl(filePath);
    if(openCSVFile(filePath)){
        dataList_.clear();
        QString tmpStr;
        QStringList strList;
        QTextStream stream(&csvFile_);
        while (!stream.atEnd()) {
            tmpStr = stream.readLine();
            strList = tmpStr.split(separator_);
            strList.pop_back();
            dataList_.push_back(strList);
        }
        csvFile_.close();
        emit fileIsParsed();
    }
    else
        emit sendInfoMsg(fileUrl + " was not opened.");
}
