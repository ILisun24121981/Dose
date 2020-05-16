#include "report_manager.h"
#include "settings.h"
#include <QDebug>
#include <QMessageBox>
#include "trash_cleaner.h"

Lis::Report_manager::Report_manager(Controller *ct, QObject *parent):Processor(ct,parent){

}

void Lis::Report_manager::update_common_raw_report(){
    Trash_cleaner trash;
    //используется как сборщик мусора
    //при выходе из функции переменная удаляется
    //и согласно логике Qt удаляет всех child

    QString reportName = "CommonRawReport.txt";
    QStringList *lastUpdatePoint = new QStringList();
    QFile *comRawRep = new QFile((Lis::Settings::get_instance()->get(Lis::Setting_name::Common_reports_folder))+reportName,&trash);
    if(comRawRep->open(QIODevice::WriteOnly | QFile::Text)){
        qDebug()<<"CommonRawReport.txt opened";
        //Ищем точку которой закончилось последнее обновление отчета
        this->_controller->_logger->find_last_updated_point_data(reportName,lastUpdatePoint);
        qDebug()<<lastUpdatePoint->at(Updated_point::File_name);
        qDebug()<<lastUpdatePoint->at(Updated_point::Time_date);
        QFile *source = new QFile((Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_standard_reports_folder))+(lastUpdatePoint->at(Updated_point::File_name)),&trash);
        if (!source->open(QIODevice::ReadOnly | QIODevice::Text)){
             QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + lastUpdatePoint->at(Updated_point::File_name) +" from where "+reportName+" update was finished");
        }else{
            copy_data(comRawRep,source,&(lastUpdatePoint->at(Updated_point::Time_date)));

        }
    }
    while(1){

    }
    delete lastUpdatePoint;
}

void Lis::Report_manager::copy_data(QFile *destination,QFile *source,const QString *row ){

    QTextStream in(source);
    QTextStream out(destination);
    QString line;


    if(destination->size()==0){//если файл чистый  - только создан.
        line = in.readLine();
        out << line <<"\n";
    }

    int rawfound =0;
    if(row ==nullptr){//если не передана строка после которой начинать копирование
        rawfound =1;
    }

    while (!in.atEnd()) {
        line = in.readLine();
        if(rawfound ==1){
           out << line <<"\n";
        }else{
            //Ищем подходящую строку в файле
            QRegExp search("^("+ *row +").*$");
            int pos=search.indexIn(line);
            if(pos!=-1){
                qDebug()<<"Raw_is_found:"+line;
                rawfound =1;
            }
        }
    }
}





//QString copy_raw_from_report(QFile *report){

//}

