#include "report_manager.h"
#include "settings.h"
#include <QDebug>
#include <QMessageBox>
#include "trash_cleaner.h"
#include "txt_helper.h"

Lis::Report_manager::Report_manager(Controller *ct, QObject *parent):Processor(ct,parent){

}

void Lis::Report_manager::update_common_raw_report(){
    Trash_cleaner trash;
    //используется как сборщик мусора
    //при выходе из функции переменная удаляется
    //и согласно логике Qt удаляет всех child

    Txt_helper helper;

    QString reportName = "CommonRawReport.txt";
    QStringList *lastUpdatePoint = new QStringList();
    QString cowRawRepLink = (Lis::Settings::get_instance()->get(Lis::Setting_name::Common_reports_folder))+ reportName;
    QFile *comRawRep = new QFile(cowRawRepLink,&trash);
    if(comRawRep->open(QIODevice::ReadWrite | QFile::Text)){
        qDebug()<<"CommonRawReport.txt opened";
        //Ищем точку которой закончилось последнее обновление отчета
        bool point_found =_controller->_logger->find_last_updated_point_data(reportName,lastUpdatePoint);
        if(point_found){
            qDebug()<<"1";
            QString pointFileName =lastUpdatePoint->at(Updated_point::File_name);
            QString pointFileFolderLink = (Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_standard_reports_folder))+pointFileName;
            QFile *source = new QFile(pointFileFolderLink,&trash);
            if (!source->open(QIODevice::ReadOnly | QIODevice::Text)){
                 QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + lastUpdatePoint->at(Updated_point::File_name) +" from where "+reportName+" update was finished");
            }else{
                qDebug()<<"2";
                helper.copy_lines(comRawRep,source,&(lastUpdatePoint->at(Updated_point::Time_date)));
            }
        }




    }
    comRawRep->flush();
    comRawRep->close();
    delete lastUpdatePoint;
}








