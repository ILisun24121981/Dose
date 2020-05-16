#include "report_manager.h"
#include "settings.h"
#include <QDebug>
#include <QMessageBox>

Lis::Report_manager::Report_manager(Controller *ct, QObject *parent):Processor(ct,parent){

}

void Lis::Report_manager::update_common_raw_report(){
    QString reportName = "CommonRawReport.txt";
    QStringList *lastUpdatePoint;
    QFile comRawRep((Lis::Settings::get_instance()->get(Lis::Setting_name::Common_reports_folder))+reportName);
    if(comRawRep.open(QIODevice::WriteOnly | QFile::Text)){
        int headered =1;
        if(comRawRep.size()==0){//если файл чистый  - только создан.
           headered =0;//нет заголовка
        }
        qDebug()<<"CommonRawReport.txt opened";
        //Ищем точку которой закончилось последнее обновление отчета
        lastUpdatePoint = this->_controller->_logger->find_last_updated_point_data(reportName);
        qDebug()<<lastUpdatePoint->at(Updated_point::File_name);
        qDebug()<<lastUpdatePoint->at(Updated_point::Time_date);
        QFile target((Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_standard_reports_folder))+(lastUpdatePoint->at(Updated_point::File_name)));
        if (!target.open(QIODevice::ReadOnly | QIODevice::Text)){
             QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + lastUpdatePoint->at(Updated_point::File_name) +" from where "+reportName+" update was finished");
        }else{
            QTextStream in(&target);
            QTextStream out(&comRawRep);
            int rawfound =0;

            while (!in.atEnd()) {
                QString line = in.readLine();
                if(rawfound ==1){
                   out << line <<"\n";
                }else{
                    if(headered == 0){
                       out << line <<"\n";
                       headered =1;
                    }
                    //Ищем подходящую строку в файле
                    QRegExp search("^("+lastUpdatePoint->at(Updated_point::Time_date)+").*$");
                    int pos=search.indexIn(line);
                    if(pos!=-1){
                        qDebug()<<"Raw_is_found:"+line;
                        rawfound =1;
                    }
                }
            }
        }
    }
    delete lastUpdatePoint;
}






//QString copy_raw_from_report(QFile *report){

//}

