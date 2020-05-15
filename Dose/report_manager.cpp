#include "report_manager.h"
#include "settings.h"
#include <QDebug>

Lis::Report_manager::Report_manager(Controller *ct, QObject *parent):Processor(ct,parent){

}

void Lis::Report_manager::update_common_raw_report(){
    QStringList *lastUpdatePoint;
    QFile *comRawRep;
    comRawRep = new QFile((Lis::Settings::get_instance()->get(Lis::Setting_name::Common_reports_folder))+"CommonRawReport.txt");
    comRawRep->open(QIODevice::WriteOnly | QFile::Text);
    qDebug()<<"CommonRawReport.txt opened";
    lastUpdatePoint = this->_controller->_logger->find_last_updated_point("CommonRawReport.txt");
    qDebug()<<lastUpdatePoint->at(Updated_point::File_name);
    qDebug()<<lastUpdatePoint->at(Updated_point::Time_date);
}
//QString copy_raw_from_report(QFile *report){

//}

