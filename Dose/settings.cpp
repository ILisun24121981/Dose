#include "settings.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QRegExp>

Lis::Settings::Settings()
{
    this->read();
}
QString Lis::Settings::read(){
    QFile Settingfile("Settings.txt");
    if (!Settingfile.open(QIODevice::ReadOnly | QIODevice::Text)){
         QMessageBox::information(NULL, QObject::tr("Error"),"Can not open Setting file");
    }else{
        qDebug()<<"file opened";
        QTextStream in(&Settingfile);
        QString text;
         qDebug()<<"1";
        while (!in.atEnd()) {
            QString line = in.readLine();
    //(?=.*CATEGORY\\sNAME:(\\s?|\\s+))(.*)(?=(\\s?|\\s+)PARAMETER.*)

            QRegExp name("(?:\")(.*)(?=\".*)");
            int pos=name.indexIn(line);
            if(pos!=-1){
                text = name.cap(1);
                qDebug()<<text;
                QRegExp value("(?:<)(.*)(?=>.*)");
                pos=value.indexIn(line);
                if(pos!=-1){
                    text = value.cap(1);
                    qDebug()<<text;
                    this->_settings.append(text);
                    qDebug()<<this->_settings;
                }else{
                    QMessageBox::information(NULL, QObject::tr("Error"),"check setting file for setted "+text);
               }
            }
        }
    }
}