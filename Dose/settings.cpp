#include "settings.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QRegExp>

Lis::Settings* Lis::Settings::get_instance(){
    if(Lis::Settings::_instance == NULL){
        _instance = new Settings();
    }
    return _instance;
}

Lis::Settings::Settings()
{
    _settings = new QVector<QString> ();
    _initResult = this->init();
}

Lis::Settings::~Settings(){   
    delete _settings;
    delete _instance;
}

bool Lis::Settings::init(){

    QFile Settingfile("Settings.txt");
    if (!Settingfile.open(QIODevice::ReadOnly | QIODevice::Text)){
         QMessageBox::information(NULL, QObject::tr("Error"),"Can not open Setting file");
         return false;
    }else{
        qDebug()<<"file opened";
        QTextStream in(&Settingfile);
        QString text;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QRegExp name("(?:\")(.*)(?=\".*)");
            int pos=name.indexIn(line);
            if(pos!=-1){
                text = name.cap(1);
                qDebug()<<"What:"+text;
                QRegExp value("(?:<)(.*)(?=>.*)");
                pos=value.indexIn(line);
                if(pos!=-1){
                    text = value.cap(1);
                    text.replace("\\","/");
                    qDebug()<<"Where:"+text;
                    this->_settings->append(text);
                }else{
                    QMessageBox::information(NULL, QObject::tr("Error"),"check setting file for setted "+text);
                    return false;
               }
            }
        }
    }
   return true;
}

QString Lis::Settings::get(Setting_name sn){
    return _settings->value(sn);
}
