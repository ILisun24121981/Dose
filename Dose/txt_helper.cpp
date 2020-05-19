#include "txt_helper.h"
#include <QTextStream>
#include <QRegExp>
#include <QDebug>
#include <QMessageBox>

Lis::Txt_helper::Txt_helper()
{

}

QString Lis::Txt_helper::find_line_in_file(const QString &pattern, QFile *file){
    //ищет в файле строку подходящую шаблону

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
QString Lis::Txt_helper::find_data_in_line(const QString &pattern,const QString line){
    //ищет в строке данные соответствующие шаблону.

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
QString Lis::Txt_helper::copy_lines(QFile *destination,QFile *source,const QString &pattern ){
    //копирует из файла source все строки ниже строки,
    //подходящей шаблону pattern в файл destination
    //Если строка не задана -копирует все строки
    //Возвращает последнюю скопированную строку
    //Если строка подходящая шаблону не найдена возвращает NULL

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
    //Заменяет строку подходящую по шаблону pattern в файле source
    //на новую newline

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
QString Lis::Txt_helper::convert_date_to_file_name(const QString date){
    //преобразовывает формат записи даты полученной из строки
    //к формату записи даты для именования стандартных отчетов

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
    qDebug()<<"Source file of last line is: "+convertedDate;
    return convertedDate;

}

QStringList* Lis::Txt_helper::get_file_list(QString dir,QString borderFile){
    //Функция возвращает список имен файлов директории
    //полученный в результате сортировки (по возрастанию)по имени
    //и исключения файлов предшествующих (меньше) имени borderFile(включительно)
    //Возвращает список всех файлов если borderFile не задан
    //Возвращает nullptr если нет файлов после borderFile

    QStringList *fl =new QStringList();
    QDir *direct = new QDir(dir);
    direct->setSorting(QDir::Name);
    QStringList *tempfl =new QStringList(direct->entryList());

    int i=2, founded = 0;
    if(borderFile != NULL){
       i=tempfl ->lastIndexOf(borderFile)+1;
    }

    while(i<tempfl->size()){
        qDebug()<<"i =";
        qDebug()<<i;
        fl->append(tempfl->at(i));
        founded =1;
        i++;

    }
    delete direct;
    delete tempfl;
    if(founded == 0){
        qDebug()<<"No files to copy";
        delete fl;
        return nullptr;
    }
    qDebug()<<"List of file to copy from dir: "+ dir +" is: ";
    qDebug()<<*fl;
    return fl;

}
void Lis::Txt_helper::copy_files_to_file (QFile *destination, const QString sourceDir, QStringList *sourcefileList){
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
