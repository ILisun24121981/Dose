#include "txt_logger.h"

#include "settings.h"
#include <QMessageBox>
#include <QDebug>
#include <QStringListIterator>
#include <QFile>

Lis::Txt_logger::Txt_logger()
{

    _logFileLink = (Lis::Settings::get_instance()->get(Lis::Setting_name::Logs_file_folder))+"Logs.txt";
    qDebug()<<"Logs.txt link saved";

}
QStringList* Lis::Txt_logger::find_last_updated_point_data(QString reportName){
    qDebug()<<"Cap ";
    QStringList *point = new QStringList();
    QFile logFile(_logFileLink);
    if(logFile.open(QIODevice::ReadWrite | QFile::Text)){
        QTextStream in(&logFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            //Ищем подходящую строку в файле
            QRegExp search("^("+reportName+"\\slast\\supdated\\spoint:\\s).*$");        //("(?:\")(.*)(?=\".*)");
            int pos=search.indexIn(line);
            if(pos!=-1){
                qDebug()<<"Raw_is_found:"+line;
                //Ищем название файла
                search.setPattern("(?:file=)(.*)(?=,.*)");
                pos=search.indexIn(line);
                if(pos!=-1){
                    qDebug()<<"Cap2 present";
                    point->append(search.cap(1));
                    search.setPattern("(?:time/date=)(.*)$");
                    pos=search.indexIn(line);
                    if(pos!=-1){
                        qDebug()<<"Cap3 present";
                        point->append(search.cap(1));
//                        //Заготовка для тестирования регулярки
//                        QStringList list;
//                        list = search.capturedTexts();
//                        QStringListIterator iter(list);
//                        while(iter.hasNext()){
//                            qDebug()<<iter.next();
//                        }
                    }else{
                        qDebug()<<"No cap3";
                    }
                }else{
                   qDebug()<<"No cap2";
                }
            }else{
                qDebug()<<"No cap1";
            }
        }
    }
    return point;
}






