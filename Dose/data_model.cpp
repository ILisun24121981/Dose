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

}

Lis::DATA Lis::Data_Model::get_data(){

    int first;
    DATA data;

    DATA* ptr1 = &data;
    qDebug()<<"локальный указатель DATA* ptr1 =;";
    qDebug()<<ptr1;

    Txt_helper helper;
    QString dir = Lis::Settings::get_instance()->get(Lis::Setting_name::Raw_personal_reports_folder);
    QStringList filelist = helper.get_files_list_from_dir(dir);
    if(!filelist.isEmpty()){
        for(const QString &x: filelist){

            USER_POINTS up;

            USER_POINTS* ptr2 = &up;
            qDebug()<<"локальный указатель USER_POINTS* ptr2 =;";
            qDebug()<<ptr2;

            QString pattern = "^(.+)_";//шаблон для выделения имени из названия файла
            up.first = helper.get_data_from_line(pattern,x);
            qDebug()<<"Формируем список для "+up.first;
            QFile source(dir+ x);
            if(!source.open(QIODevice::ReadOnly | QFile::Text)){
                QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + x +" to continue copiing lines");
                return data;
            }
            QTextStream in(&source);
            first = 0;//пропуск первой строки - заголовка
            while (!in.atEnd()) {
                qDebug()<<"Сканируем строку";
                QString line = in.readLine();
                if(first!= 0){
                    pattern ="^(\\S+)\\s";//шаблон извлекающий дату из строки
                    QString datetime = helper.get_data_from_line(pattern,line);
                    qDebug()<<"date is: "+datetime;
                    datetime =helper.convert_date_format(datetime);
                    pattern ="(\\d+:\\d+:\\d+\\s*(AM|PM))";
                    datetime = datetime +" "+ helper.get_data_from_line(pattern,line);
                    qDebug()<<"datetime is: "+datetime;

                    TIME_POINT tp;
                    tp.first = datetime;

                    TIME_POINT* ptr3 = &tp;
                    qDebug()<<"локальный указатель USER_POINTS* ptr3 =;";
                    qDebug()<<ptr3;

                    QList<float> tpl;

                    QList<float>* ptr4 = &tpl;
                    qDebug()<<"локальный указатель USER_POINTS.QList<float>* ptr4 =;";
                    qDebug()<<ptr4;

                    qDebug()<<"Ищем данные в строке";
                    pattern = ";?([^;]+);?";
                    QRegExp search(pattern);
                    int count = 0;
                    int pos = 0;
                    qDebug()<<"значение pos == 0?:";
                    qDebug()<<"TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT";
                    qDebug()<<pos;
                    while((pos =search.indexIn(line,pos))!= -1){
                        ++count;
                        qDebug()<<"значение pos:";
                        qDebug()<<pos;

//                            //Заготовка для тестирования регулярки
//                            qDebug()<<"Все захваченные совпадения";
//                            QStringList list;
//                            list = search.capturedTexts();
//                            QStringListIterator iter(list);
//                            while(iter.hasNext()){
//                                qDebug()<<"captured";
//                                qDebug()<<iter.next();
//                            }
                        qDebug()<<"Возмем это:";
                        qDebug()<<search.cap(1);
                       // tpl<< search.cap(1).toFloat();
                        pos += search.cap(1).length()+1;
                        if(count>6){
                            qDebug()<<"захватить эти данные";
                        }
                    }
                }
                first =1;
            }
        }
    }
}


//Lis::DATA* Lis::Data_Model::get_data(QFile* source){
//    QTextStream in(source);
//    QString line;
//    Lis::DATA* data = new Lis::DATA();

//    QRegExp pattern = ;



//    while (!in.atEnd()) {
//        int pos;
//        line = in.readLine();
//        pos= pattern.indexIn(line);
//        if(pos!=-1){
////                            //Заготовка для тестирования регулярки
////                            QStringList list;
////                            list = search.capturedTexts();
////                            QStringListIterator iter(list);
////                            while(iter.hasNext()){
////                                qDebug()<<"captured";
////                                qDebug()<<iter.next();
////                            }
//           qDebug()<<"captured";
//    }

//}


