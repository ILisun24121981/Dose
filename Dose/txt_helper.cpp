#include "txt_helper.h"
#include <QTextStream>

Txt_helper::Txt_helper()
{

}

QString Txt_helper::find_line_in_file(const QString &pattern, QFile *file){
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
QString Txt_helper::find_data_in_line(const QString &pattern, QString line){
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


