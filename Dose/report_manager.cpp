#include "report_manager.h"
#include "settings.h"
#include <QDebug>
#include <QMessageBox>
#include "trash_cleaner.h"
#include "txt_helper.h"

Lis::Report_manager::Report_manager(Controller *ct, QObject *parent):Processor(ct,parent){

}

void Lis::Report_manager::update_common_raw_report(){

    Txt_helper helper;

    const QString reportName = "CommonRawReport.txt";
    QString timeData;
    QString fileData;
    QString line;
    QString Link = (Lis::Settings::get_instance()->get(Lis::Setting_name::Common_reports_folder))+ reportName;
    QFile comRawRep(Link);
    if(comRawRep.open(QIODevice::ReadWrite | QFile::Text)){
        qDebug()<<"CommonRawReport.txt opened";
        //Ищем точку которой закончилось последнее обновление отчета
        bool point_found =_controller->_logger->find_last_updated_line_data(reportName,fileData,timeData);
        if(point_found){
            QString Link = (Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_standard_reports_folder))+fileData;
            QFile source(Link);
            if (!source.open(QIODevice::ReadOnly | QIODevice::Text)){
                 QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + fileData +" from where "+reportName+" update was finished");
            }else{
                QString pattern = "^("+ timeData +").*$";
                line = helper.copy_lines(&comRawRep,&source,pattern);
                if(line ==NULL){
                    return;
                }
                qDebug()<<"Last Copied line:"+line;
                pattern ="^([^;]*);";
                timeData = helper.find_data_in_line(pattern,line);
                _controller->_logger->set_last_updated_line_data(reportName,fileData,timeData);

            }
        }


    }
    comRawRep.flush();
    comRawRep.close();
}








