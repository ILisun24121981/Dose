#include "txt_logger.h"

#include "settings.h"
#include <QMessageBox>
#include <QDebug>

Lis::Txt_logger::Txt_logger()
{

    _logFile = new QFile(Lis::Settings::get_instance()->get(Lis::Settings::Setting_name::File_to_store_logs));
    _logFile->open(QIODevice::WriteOnly | QFile::Text);
     qDebug()<<"Logs.txt opened";
}






