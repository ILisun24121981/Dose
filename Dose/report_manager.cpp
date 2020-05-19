#include "report_manager.h"
#include "settings.h"
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include "trash_cleaner.h"
#include "txt_helper.h"

Lis::Report_manager::Report_manager(Controller *ct, QObject *parent):Processor(ct,parent){

}

void Lis::Report_manager::update_common_raw_report(){
    Txt_helper helper;
    QString line;
    QString pattern;
    QStringList *filelist;
    QString fileName = "CommonRawReport.txt";
    QString dir = Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_reports_folder);
    QFile comRawRep(dir+ fileName);
    comRawRep.open(QIODevice::ReadWrite | QFile::Text);
    qDebug()<<"CommonRawReport.txt opened";
    line =helper.get_last_line(&comRawRep);
    qDebug()<<"Last line in "+fileName+" is: " +line;
    dir = Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_standard_reports_folder);
    if(line!=NULL){
        pattern ="^(\\S+)\\s";//шаблон извлекающий дату из строки
        QString date = helper.find_data_in_line(pattern,line);
        qDebug()<<"date is: "+date;
        fileName =helper.convert_date_to_file_name(date);
        QFile source(dir+ fileName);
        if(!source.open(QIODevice::ReadOnly | QFile::Text)){
            QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + fileName +" to continue copiing lines");
            return;
        }
        helper.copy_lines(&comRawRep,&source,line);
        filelist =helper.get_file_list(dir,fileName);
    }else{
        filelist =helper.get_file_list(dir);
    }
    if(filelist == nullptr){
        return;
    }
    helper.copy_files_to_file(&comRawRep,dir,filelist);
    delete filelist;
}

void Lis::Report_manager::update_personal_raw_reports(){

    QStringList *loginList =get_login_list();

    int i=0;
    while (i<loginList->size()){
        i++;
    }

}

QStringList* Lis::Report_manager::get_login_list(){
    QFile loginfile((Settings::get_instance()->get(Lis::Setting_name::Logins_and_passports_file_folder)+ "Login.txt"));
    if (!loginfile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(NULL, QObject::tr("Error"),"Passport_file_problem");
        return nullptr;
    }
    QStringList *list = new QStringList();
    QTextStream in(&loginfile);
    QRegExp search("name:(.+)\\s");
    while (!in.atEnd()) {
        QString line = in.readLine();
        //Ищем подходящую строку в файле
        int pos=search.indexIn(line);
        if(pos!=-1){
           list->append(search.cap(1));
        }
    }
    qDebug()<<"Lofin list: ";
    qDebug()<<*list;
    return list;

}

//void Lis::Report_manager::update_common_raw_report(){

//    Txt_helper helper;

//    const QString reportName = "CommonRawReport.txt";
//    QString timeData;
//    QString fileData;
//    QString line;
//    QString Link = (Lis::Settings::get_instance()->get(Lis::Setting_name::Common_reports_folder))+ reportName;
//    QFile comRawRep(Link);
//    if(comRawRep.open(QIODevice::ReadWrite | QFile::Text)){
//        qDebug()<<"CommonRawReport.txt opened";
//        //Ищем точку которой закончилось последнее обновление отчета
//        bool point_found =_controller->_logger->find_last_updated_line_data(reportName,fileData,timeData);
//        if(point_found){
//            QString Link = (Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_standard_reports_folder))+fileData;
//            QFile source(Link);
//            if (!source.open(QIODevice::ReadOnly | QIODevice::Text)){
//                 QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + fileData +" from where "+reportName+" update was finished");
//            }else{
//                QString pattern = "^("+ timeData +").*$";
//                line = helper.copy_lines(&comRawRep,&source,pattern);
//                if(line == NULL){
//                    return;
//                }
//                qDebug()<<"Last Copied line:"+line;
//                pattern ="^([^;]*);";
//                timeData = helper.find_data_in_line(pattern,line);
//                _controller->_logger->set_last_updated_line_data(reportName,fileData,timeData);

//            }
//        }


//    }
//    comRawRep.flush();
//    comRawRep.close();
//}








