#include "txt_helper.h"
#include <QTextStream>
#include <QDebug>

Lis::Txt_helper::Txt_helper()
{

}

QString Lis::Txt_helper::find_line_in_file(const QString &pattern, QFile *file){
    QTextStream in(file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //Ищем подходящую строку в файле
        QRegExp search(pattern);
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
//            qDebug()<<iter.next();
//        }
        return search.cap(1);
    }
    return NULL;
}
void Lis::Txt_helper::copy_lines(QFile *destination,QFile *source,const QString *row ){//row - строка ниже которой будет производиться копирование

    QTextStream in(source);
    QTextStream out(destination);
    QString line;


    if(destination->size()==0){//если файл чистый  - только создан.
        line = in.readLine();
        out << line <<"\n";
    }

    int rawfound =0;
    if(row ==nullptr){//если не передана строка после которой начинать копирование
        rawfound =1;
    }

    while (!in.atEnd()) {
        line = in.readLine();
        if(rawfound ==1){
           out << line <<"\n";
        }else{
            //Ищем подходящую строку в файле
            QRegExp search("^("+ *row +").*$");
            int pos=search.indexIn(line);
            if(pos!=-1){
                qDebug()<<"Raw_is_found:"+line;
                rawfound =1;
            }
        }
    }
}


