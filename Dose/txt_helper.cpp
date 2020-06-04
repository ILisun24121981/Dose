#include "txt_helper.h"
#include <QTextStream>
#include <QRegExp>
#include <QDebug>
#include <QMessageBox>

Lis::Txt_helper::Txt_helper()
{

}

QString Lis::Txt_helper::get_line_from_file(const QString &pattern, QFile *file){
    //возвращает из файла строку подходящую шаблону

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

QString Lis::Txt_helper::copy_lines(QFile *destination, QFile *source, const QString &startpattern, const QString &pattern){
    //копирует из файла source все строки ниже строки,
    //подходящей шаблону startpattern и удовлетворяющие шаблону pattern в файл destination
    //Если startpattern не задана -копирует все строки удовлетворяющие шаблону pattern
    //Если pattern не задан -копирует все строки ниже startpattern
    //Возвращает последнюю скопированную строку
    //Если строка подходящая шаблону не найдена возвращает NULL

    qDebug()<<"Copying lines startpattern -"+startpattern+ "pattern-"+pattern;
    qDebug()<<"from "+source->fileName();
    qDebug()<<"to "+destination->fileName();

    QTextStream in(source);
    QTextStream out(destination);
    QString line;

    qDebug()<<destination->fileName()+" size before copying: ";
    qDebug()<<destination->size();

    if((destination->size())== 0){//если файл чистый  - только создан - копируем заголовок
        line = in.readLine();
        out << line <<"\n";
    }else{
        line = in.readLine();//пропускаем заголовок
        out.seek(destination->size());//если файл не чистый - встаем в конец файла для записи
    }

    int rawfound =0,filtering =1;

    if(startpattern == NULL){//если не передан шаблон строки после которой начинать копирование
        rawfound =1;
        qDebug()<<"Start copying form begining of file";
    }
    if(pattern == NULL){
        filtering =0;
        qDebug()<<"filtering disabled";
    }else{
        qDebug()<<"filtering enabled";
    }

    QRegExp search(startpattern);
    QRegExp filter(pattern);

    int copied =0;

    while (!in.atEnd()) {
        int pos;
        line = in.readLine();
        if(rawfound ==1){
            qDebug()<<"proccess:";
            if(filtering ==1){
                qDebug()<<"Filtering";
                pos=filter.indexIn(line);
                if(pos!=-1){
//                            //Заготовка для тестирования регулярки
//                            QStringList list;
//                            list = search.capturedTexts();
//                            QStringListIterator iter(list);
//                            while(iter.hasNext()){
//                                qDebug()<<"captured";
//                                qDebug()<<iter.next();
//                            }
                   qDebug()<<"captured";
                   out << line <<"\n";
                   copied = 1;
                }
            }else{
                qDebug()<<"captured";
                out << line <<"\n";
                copied = 1;
            }
        }else{
            //Ищем подходящую startpattern строку в файле source
            pos=search.indexIn(line);
            if(pos!=-1){
                qDebug()<<"Raw_to_start_copying_is_found:"+line;
                rawfound =1;
            }
        }
    }
    out.flush();
    qDebug()<<destination->fileName()+" size after copying: ";
    qDebug()<<destination->size();
    destination->seek(0);
    source->seek(0);
    if(copied ==1){
        return line;
    }
    qDebug()<<"No line to copy";
    return NULL;
}

//bool Lis::Txt_helper::replace_line(const QString &pattern, const QString newline,QFile *source,QFile *temp){
//    //Заменяет строку подходящую по шаблону pattern в файле source
//    //на новую newline

//    QTextStream in(source);
//    QTextStream out(temp);
//    QRegExp search(pattern);
//    int replaced =0;

//    while (!in.atEnd()) {
//        QString line = in.readLine();
//        //Ищем подходящую строку в файле
//        int pos=search.indexIn(line);
//        if(pos!=-1){
//           out << newline;
//           qDebug()<<"line: "+line+" replaced with line:"+newline;
//           replaced =1;
//        }else{
//           out<<line;
//        }
//    }
//    if(replaced ==1){
//        out.flush();
//        in.seek(0);
//        out.seek(0);

//        while (!out.atEnd()) {
//            QString line = out.readLine();
//            in << line;
//        }
//        in.flush();
//        source->seek(0);
//        return true;
//    }
//    source->seek(0);
//    qDebug()<<"line to replace not found";
//    return false;
//}

QString Lis::Txt_helper::get_last_line(QFile *file){
    //возвращает последнюю строку файла

    QString line;

    if((file->size())== 0){//если файл чистый  - только создан - копируем заголовок
        return NULL;
    }
    QTextStream in(file);

    int header =0;
    int data =0;

    while (!in.atEnd()) {
        line = in.readLine();
        if(header ==0){
            header =1;
        }else{
            data =1;
        }
    }
    file->seek(0);
    if(data ==0){
       return NULL;
    }
    return line;

}
QString Lis::Txt_helper::convert_date_format(const QString date){
    //преобразовывает формат записи даты полученной из строки
    //к формату записи даты для именования стандартных отчетов

    QString temp;
    QString convertedDate;
    QString pattern ="\\d";
    QRegExp check(pattern);

    pattern = "/([^/]+)$";
    convertedDate = get_matched_from_line(pattern,date);
    pattern = "^([^/]+)/";
    temp = get_matched_from_line(pattern,date);
    if(temp.count(check)==1){
       convertedDate=convertedDate+"0";
    }
    convertedDate+=temp;
    pattern = "(?:/)([^/]+)(?:/)";
    temp = get_matched_from_line(pattern,date);
    if(temp.count(check)==1){
       convertedDate=convertedDate+"0";
    }
    convertedDate+=temp;    
    return convertedDate;

}

QStringList Lis::Txt_helper::get_files_list_from_dir(const QString dir,const QString borderFileName){
    //Функция возвращает список имен файлов директории
    //полученный в результате сортировки (по возрастанию)по имени
    //и исключения файлов предшествующих (меньше) имени borderFile(включительно)
    //Возвращает список всех файлов если borderFile не задан
    //Возвращает nullptr если нет файлов после borderFile

    QStringList fl;
    QDir direct(dir);
    direct.setSorting(QDir::Name);
    QStringList tempfl(direct.entryList());

    int i=2, founded = 0;
    if(borderFileName != NULL){
       i=tempfl.lastIndexOf(borderFileName)+1;
    }

    while(i<tempfl.size()){
        fl.append(tempfl.at(i));
        founded =1;
        i++;

    }

    if(founded == 0){
        qDebug()<<"No files to copy";       
    }
    qDebug()<<"List of file to copy from dir: "+ dir +" is: ";
    qDebug()<<fl;
    return fl;
}

void Lis::Txt_helper::copy_files_to_file (QFile *destination, const QString sourceDir,const QStringList *sourcefileList){
    //копирует все строки файлов перечисленных в sorcefileList находящихся в директории
    //sourceDir в файл destination
    int i=0;
    while(i<sourcefileList->size()){
        QFile source(sourceDir+sourcefileList->at(i));
        if(!source.open(QIODevice::ReadOnly | QFile::Text)){
            QMessageBox::information(NULL, QObject::tr("Error"),"Can not open " + sourcefileList->at(i) +" to continue copiing lines");
            return;
        }
        copy_lines(destination,&source);
        i++;
    }

}

QString Lis::Txt_helper::get_matched_from_line(const QString &pattern,const QString line){
    //возвращает из строки данные соответствующие шаблону.

    QRegExp search(pattern);
    int pos=search.indexIn(line);
    if(pos!=-1){
        //Заготовка для тестирования регулярки
        QStringList list;
        list = search.capturedTexts();
        QStringListIterator iter(list);
        while(iter.hasNext()){
            qDebug()<<"captured";
            qDebug()<<iter.next();
        }
        //
        return search.cap(1);
    }
    return NULL;
}

QList<QString> Lis::Txt_helper::get_all_matched_from_line(QString pattern, QString line){
    QList<QString> list;

    QList<QString>* ptr;
    qDebug()<<"локальный указатель на скисок параметров возвращаемый из get_all_matched_from_line;";
    qDebug()<<ptr;

    QRegExp search(pattern);
    int count = 0;
    int pos = 0;
    //qDebug()<<"значение pos == 0?:";
    //qDebug()<<pos;
    while((pos =search.indexIn(line,pos))!= -1){
        ++count;
        pos += search.cap(1).length()+1;
        list<< search.cap(1);
    }
    return list;
}




