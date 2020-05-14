#include "report_manager.h"
#include "settings.h"
#include <QDebug>

Lis::Report_manager::Report_manager(Controller *ct)
{

}

void Lis::Report_manager::update_common_raw_report(){

    _comRawRep = new QFile((Lis::Settings::get_instance()->get(Lis::Setting_name::Common_reports_folder))+"CommonRawReport.txt");
    _comRawRep->open(QIODevice::WriteOnly | QFile::Text);
    qDebug()<<"CommonRawReport.txt opened";

}
