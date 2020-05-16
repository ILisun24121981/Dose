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
    qDebug()<<"Logs.txt link saved";

}
bool Lis::Txt_logger::find_last_updated_point_data(QString reportName,QStringList *point){
    Txt_helper helper;
    qDebug()<<"Serching last updated point of "+reportName+" in Logs.txt";
    QFile logFile(_logFileLink);
    if(logFile.open(QIODevice::ReadWrite | QFile::Text)){
        QString pattern = "^("+reportName+"\\slast\\supdated\\spoint:\\s).*$";
        QString line =helper.find_line_in_file(pattern,&logFile);
        if(line !=NULL){
            pattern = "(?:file=)(.*)(?=,.*)";
            QString file = helper.find_data_in_line(pattern,line);
            qDebug()<<"File:"+file;
            if(file != NULL){
                point->append(file);
                pattern = "(?:time/date=)(.*)$";
                QString timedate = helper.find_data_in_line(pattern,line);
                qDebug()<<"Time/Date: "+file;
                if(timedate!=NULL){
                    point->append(timedate);
                    return true;
                }
            }
        }
    }
    return false;
}











//    qDebug()<<"Searching "+ reportName +"last updated point data in Logs.txt ";
//    QFile logFile(_logFileLink);
//    if(logFile.open(QIODevice::ReadWrite | QFile::Text)){
//        QTextStream in(&logFile);
//        while (!in.atEnd()) {
//            QString line = in.readLine();
//            //Ищем подходящую строку в файле
//            QRegExp search("^("+reportName+"\\slast\\supdated\\spoint:\\s).*$");        //("(?:\")(.*)(?=\".*)");
//            int pos=search.indexIn(line);
//            if(pos!=-1){
//                qDebug()<<"Raw_is_found:"+line;
//                //Ищем название файла
//                search.setPattern("(?:file=)(.*)(?=,.*)");
//                pos=search.indexIn(line);
//                if(pos!=-1){
//                    point->append(search.cap(1)); // название файла добавлено в point
//                    search.setPattern("(?:time/date=)(.*)$");
//                    pos=search.indexIn(line);
//                    if(pos!=-1){
//                        point->append(search.cap(1));//дата время добавлено в point
////                        //Заготовка для тестирования регулярки
////                        QStringList list;
////                        list = search.capturedTexts();
////                        QStringListIterator iter(list);
////                        while(iter.hasNext()){
////                            qDebug()<<iter.next();
////                        }
//                    }else{
//                        qDebug()<<"No cap3";
//                    }
//                }else{
//                   qDebug()<<"No cap2";
//                }
//            }else{
//                qDebug()<<"No cap1";
//            }
//        }
//    }
//}






