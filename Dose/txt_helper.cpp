#include "txt_helper.h"
#include <QTextStream>
#include <QRegExp>
#include <QDebug>

Lis::Txt_helper::Txt_helper()
{

}

QString Lis::Txt_helper::find_line_in_file(const QString &pattern, QFile *file){
    QTextStream in(file);
    QRegExp search(pattern);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //Ищем подходящую строку в файле      
        int pos=search.indexIn(line);
        if(pos!=-1){
           return  line;
        }
    }
    return NULL;
}
QString Lis::Txt_helper::find_data_in_line(const QString &pattern, QString line){
    QRegExp search(pattern);
    int pos=search.indexIn(line);
    if(pos!=-1){
//        //Заготовка для тестирования регулярки
//        QStringList list;
//        list = search.capturedTexts();
//        QStringListIterator iter(list);
//        while(iter.hasNext()){
//            qDebug()<<"captured";
//            qDebug()<<iter.next();
//        }
//        //
        return search.cap(1);
    }
    return NULL;
}
QString Lis::Txt_helper::copy_lines(QFile *destination,QFile *source,const QString &pattern ){//lineInSource - строка ниже которой будет производиться копирование
    //Функция копирует данные из одного отчета в другой
    //начиная со строки ниже lineInSouce
    //Если lineInSorce не была передана, то
    //копируются все строки.

    QTextStream in(source);
    QTextStream out(destination);
    QString line;

    qDebug()<<destination->fileName()+" size before copying: ";
    qDebug()<<destination->size();

    if((destination->size())== 0){//если файл чистый  - только создан - копируем заголовок
        line = in.readLine();
        out << line <<"\n";
    }else{       
       out.seek(destination->size());//если файл не чистый - встаем в конец файла для записи
    }

    int rawfound =0;
    if(pattern == NULL){//если не передан шаблон строки после которой начинать копирование
        rawfound =1;
    }

    int copied =0;
    while (!in.atEnd()) {
        line = in.readLine();
        if(rawfound ==1){
           out << line <<"\n";
           copied = 1;
        }else{
            //Ищем подходящую строку в файле
            QRegExp search(pattern);
            int pos=search.indexIn(line);
            if(pos!=-1){
                qDebug()<<"Raw_is_found:"+line;
                rawfound =1;
            }
        }
    }
    out.flush();
    qDebug()<<destination->fileName()+" size after copying: ";
    qDebug()<<destination->size();
    if(copied ==1){
        return line;
    }
    qDebug()<<"No line to copy";
    destination->seek(0);
    source->seek(0);
    return NULL;
}

bool Lis::Txt_helper::replace_line(const QString &pattern, const QString newline,QFile *source,QFile *temp){
    QTextStream in(source);
    QTextStream out(temp);
    QRegExp search(pattern);
    int replaced =0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        //Ищем подходящую строку в файле
        int pos=search.indexIn(line);
        if(pos!=-1){
           out << newline;
           qDebug()<<"line: "+line+" replaced with line:"+newline;
           replaced =1;
        }else{
           out<<line;
        }
    }
    if(replaced ==1){
        out.flush();
        in.seek(0);
        out.seek(0);

        while (!out.atEnd()) {
            QString line = out.readLine();
            in << line;
        }
        in.flush();
        return true;
    }
    qDebug()<<"line to replace not found";
    return false;
}

QString Lis::Txt_helper::get_last_line(QFile *file){
    QString line;

    if((file->size())== 0){//если файл чистый  - только создан - копируем заголовок
        return NULL;
    }
    QTextStream in(file);
    while (!in.atEnd()) {
        line = in.readLine();
    }
    return line;

}
QString Lis::Txt_helper::convert_date_to_file_name(QString date){

    QString temp;
    QString convertedDate;
    QString pattern ="\\d";
    QRegExp check(pattern);

    pattern = "/([^/]+)$";
    convertedDate = find_data_in_line(pattern,date);
    pattern = "^([^/]+)/";
    temp = find_data_in_line(pattern,date);
    if(temp.count(check)==1){
       convertedDate=convertedDate+"0";
    }
    convertedDate+=temp;
    pattern = "(?:/)([^/]+)(?:/)";
    temp = find_data_in_line(pattern,date);
    if(temp.count(check)==1){
       convertedDate=convertedDate+"0";
    }
    convertedDate+=temp;
    convertedDate+="мкЗвN2.log";
    qDebug()<<"FileName of last line is: "+convertedDate;
    return convertedDate;

}
