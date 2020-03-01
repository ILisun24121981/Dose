#include "txt_logger.h"
#include <QFile>
#include "settings.h"
#include <QMessageBox>
#include <QDebug>

Lis::Txt_logger::Txt_logger()
{
    check_log_file();
}

void Lis::Txt_logger::check_log_file(){
    QFile Logfile(Lis::Settings::getInstance()->get(Lis::Settings::Setting_name::File_to_store_logs));
    if (!Logfile.open(QIODevice::WriteOnly | QFile::Text)){
       QMessageBox::information(NULL, QObject::tr("Error"),"Can not open Log file");
    }else{
        qDebug()<<"Txt_logger_created";
    }
}
