#include "report_updater.h"
#include "settings.h"
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include "txt_helper.h"


void Lis::Report_updater::update_common_raw_report(){
    //Обновляет общий отчет ориентируясь на
    Txt_helper helper;
    QString line;
    QString pattern;
    QStringList filelist;
    QString fileName = "CommonRawReport.txt";
    QString dir = Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_common_report_folder);

    QFile comRawRep(dir+ fileName);
    comRawRep.open(QIODevice::ReadWrite | QFile::Text);
    qDebug()<<"CommonRawReport.txt opened";
    line =helper.get_last_line(&comRawRep);
    qDebug()<<"Last line in "+fileName+" is: " +line;

    dir = Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_standard_reports_folder);
    fileName.clear();

    if(line!=NULL){
        pattern ="^(\\S+)\\s";//шаблон извлекающий дату из строки
        QString date = helper.get_matched_from_line(pattern,line);
        qDebug()<<"date is: "+date;
        fileName =helper.convert_date_format(date)+"мкЗвN2.log";
        qDebug()<<"Source file of last line is: "+fileName;

        QFile source(dir+ fileName);
        if(!source.open(QIODevice::ReadOnly | QFile::Text)){
            QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + fileName +" to continue copiing lines");
            return;
        }
        helper.copy_lines(&comRawRep,&source,line);
    }
    filelist =helper.get_files_list_from_dir(dir,fileName);
    if(!filelist.isEmpty()){
        helper.copy_files_to_file(&comRawRep,dir,&filelist);
    }

}

void Lis::Report_updater::update_personal_raw_reports(){
    //обновляет персональные отчеты строками
    Txt_helper helper;
    QStringList *loginList =get_login_list();
    if(loginList == nullptr){
        return;
    }

    QFile comRawRep(Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_common_report_folder)+ "CommonRawReport.txt");
    comRawRep.open(QIODevice::ReadWrite | QFile::Text);
    if(comRawRep.size()==0){
        QMessageBox::information(NULL, QObject::tr("Alert"),"Please fill Common Raw Report firstly");
        return;
    }
    int i=0;
    while (i<loginList->size()){
        QString pattern = loginList->at(i);
        QFile persRawRep(Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_personal_reports_folder)+loginList->at(i)+"_RawReport.txt");
        persRawRep.open(QIODevice::ReadWrite | QFile::Text);
        helper.copy_lines(&persRawRep,&comRawRep,helper.get_last_line(&persRawRep),pattern);
        i++;
    }

}

QStringList* Lis::Report_updater::get_login_list(){
    QFile loginfile((Settings::get_instance()->get(Lis::Setting_name::Logins_and_passports_file_folder)+ "Login.txt"));
    if (!loginfile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(NULL, QObject::tr("Error"),"Login.txt_file_problem cant extract logins to fill logins list");
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








