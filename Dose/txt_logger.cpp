#include "txt_logger.h"

#include "settings.h"
#include <QMessageBox>
#include <QDebug>
#include <QStringListIterator>
#include <QFile>
#include "txt_helper.h"


Lis::Txt_logger::Txt_logger()
{

    _logFileLink = (Lis::Settings::get_instance()->get(Lis::Setting_name::Logs_file_folder))+"Logs.txt";
    _tempFileLink = (Lis::Settings::get_instance()->get(Lis::Setting_name::Logs_file_folder))+"tempLogs.txt";
    qDebug()<<"Logs.txt link saved";

}
bool Lis::Txt_logger::find_last_updated_line_data(const QString reportName, QString &fileData, QString &timeData){
    Txt_helper helper;
    qDebug()<<"Serching last updated point of "+reportName+" in Logs.txt";
    QFile logFile(_logFileLink);
    if(logFile.open(QIODevice::ReadWrite | QFile::Text)){
        QString pattern = "^("+reportName+"\\slast\\supdated\\spoint:\\s).*$";
        QString line =helper.get_line_from_file(pattern,&logFile);
        if(line !=NULL){
            pattern = "(?:file=)(.*)(?=,.*)";
            QString file = helper.get_data_from_line(pattern,line);
            qDebug()<<"File:"+file;
            if(file != NULL){
                fileData=file;
                pattern = "(?:time/date=)(.*)$";
                QString time = helper.get_data_from_line(pattern,line);
                qDebug()<<"Time/Date: "+time;
                if(time!=NULL){
                    timeData =time;
                    return true;
                }
            }
        }
    }
    return false;
}
//bool Lis::Txt_logger::set_last_updated_line_data(const QString reportName,const QString fileData,const QString timeData){

//    Txt_helper helper;
//    QString line = reportName+" last updated point: file="+fileData+", time/date="+timeData;
//    qDebug()<<"Serching last updated point of "+reportName+" in Logs.txt";
//    QFile logFile(_logFileLink);
//    if(logFile.open(QIODevice::ReadWrite | QFile::Text)){
//        QFile tempFile(_tempFileLink);
//        if(tempFile.open(QIODevice::ReadWrite | QFile::Text)){
//            QString pattern = "^("+reportName+"\\slast\\supdated\\spoint:\\s).*$";
//            helper.replace_line(pattern,line,&logFile,&tempFile);
//            tempFile.close();
//        }
//        logFile.close();
//    }

//}











