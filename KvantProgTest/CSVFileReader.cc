#include <QTextStream>
#include "CSVFileReader.h"

CSVFileReader::CSVFileReader(QObject *parent) : QObject(parent)
{

}

QString CSVFileReader::convertFileUrl(const QString &fileUrl)
{
//file:///media/oleg/c2593705-a894-489d-b565-859702b4a4b4/oleg/KirichekOI/GitHubRepository/KvantProgTest/KvantProgTest/TestData.csv
    QString str = fileUrl;
    str = str.replace("file://","");
    return str;
}

bool CSVFileReader::openCSVFile(const QString &filePath)
{
    csvFile.setFileName(filePath);
    return csvFile.open(QIODevice::ReadOnly | QIODevice::Text);
}

void CSVFileReader::fileParse(const QString &fileUrl)
{

    if(openCSVFile(convertFileUrl(fileUrl))){
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
    }
    else
        emit sendInfoMsg("The file was not opened.");
}
