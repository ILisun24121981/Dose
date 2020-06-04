#include "data_model.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "txt_helper.h"
#include "settings.h"
#include <QString>
#include <QMessageBox>



Lis::Data_Model::Data_Model()
{
    _data = get_data();
}

Lis::DATA Lis::Data_Model::get_data(){

    int firstScan = Lis::State::YES;
    DATA data;

    DATA* ptr1 = &data;
    qDebug()<<"локальный указатель DATA* ptr1 в функции get_data()=;";
    qDebug()<<ptr1;



    Txt_helper helper;
    QString dir = Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_personal_reports_folder);
    QStringList filelist = helper.get_files_list_from_dir(dir);

    if(!filelist.isEmpty()){
        for(const QString &x: filelist){

            USER_POINTS up;

            USER_POINTS* ptr2 = &up;
            qDebug()<<"локальный указатель USER_POINTS* созданный в get_data() ptr2 =;";
            qDebug()<<ptr2;

            QString pattern = "^(.+)_";//шаблон для выделения имени из названия файла
            up.first = helper.get_matched_from_line(pattern,x);
            qDebug()<<"Формируем список для "+up.first;

            QFile source(dir+ x);
            if(!source.open(QIODevice::ReadOnly | QFile::Text)){
                QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + x +" to continue copiing lines");
                return data;
            }
            QTextStream in(&source);

            int header =Lis::State::YES;

            while (!in.atEnd()) {//формируем список тайм поинтов для пользователя
                //qDebug()<<"Сканируем строку";

                QString line = in.readLine();
                pattern = ";?([^;]+);?";
                QList<QString> fullList = helper.get_all_matched_from_line(pattern,line);

                qDebug()<<"скисок параметров возвращенный из get_all_matched_from_line();";
                qDebug()<<fullList;
                QList<QString>* ptrl = &fullList;
                qDebug()<<"локальный указатель на скисок параметров возвращенный из get_all_matched_from_line();";
                qDebug()<<ptrl;

                int pos = 0;
                if(firstScan == Lis::State::YES){//Формируем список параметров из заголовка файла
                    QList<QString> parameterNameList;
                    for(const QString &x: fullList){
                       if(pos > Lis::Need_pos::Start && pos <Lis::Need_pos::END){//нужные данные в вернутом списке.
                           parameterNameList<<x;
                       }
                       pos++;
                     }
                    data.first<<parameterNameList;
                    firstScan = Lis::State::NO;
                    qDebug()<<"скисок имен параметров записанный в DATA;";
                    qDebug()<<data.first;
                }

                if(header == Lis::State::NO){//формируем список занчений параметров для тайм поинта
                    TIME_POINT tp;
                    QList<float> parameterValList;
                    for(const QString &x: fullList){
                       if(pos == Lis::Need_pos::TIME){//преобразовываем время и дату
                           pattern ="^(\\S+)\\s";//шаблон извлекающий дату из строки
                           QString datetime = helper.get_matched_from_line(pattern,x);
                           datetime =helper.convert_date_format(datetime);
                           pattern ="(\\d+:\\d+:\\d+\\s*(AM|PM))";
                           datetime = datetime +" "+ helper.get_matched_from_line(pattern,x);

                           tp.first =datetime;
                           qDebug()<<"Дата/время записанное в тайм поинт";
                           qDebug()<<tp.first;
                       }
                       if(pos > Lis::Need_pos::Start && pos <Lis::Need_pos::END){// нужные данные в вернутом списке.
                           parameterValList<<x.toFloat();
                       }
                       pos++;
                     }
                     tp.second<<parameterValList;
                     qDebug()<<"скисок значений параметров записанный в тайм поинт";
                     qDebug()<<tp.second;
                     up.second<< tp;
                }
                header = Lis::State::NO;
            }//сформировали список тайм поинтов для пользователя
            qDebug()<<"скисок тайм поинтов для"+up.first;
            qDebug()<<up.second;
            data.second<<up;
        }
        qDebug()<<"DATA;";
        qDebug()<<data;
    }
    return data;
}


Lis::USER_POINTS Lis::Data_Model::get_user_points(QString username){
   for(const USER_POINTS &x: _data.second){
       if(x.first == username){
           return x;
       }
   }
}




