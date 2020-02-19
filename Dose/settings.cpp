#include "settings.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QRegExp>

Lis::Settings::Settings()
{

}
QString Lis::Settings::read(){
    QFile Settingfile("S:/Ivan/Dosimeter/Dose/Files/Settings/Settings.txt");
    if (!Settingfile.open(QIODevice::ReadOnly | QIODevice::Text))
         QMessageBox::information(NULL, QObject::tr("Error"),"Can not open Setting file");
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
              int pos=value.indexIn(line);
              text = value.cap(1);
              qDebug()<<text;
           bvtyyjdfyysq v   qDebug()<<value.capturedTexts();

        }
    }
}
