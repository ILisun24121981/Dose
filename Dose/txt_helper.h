#ifndef TXT_HELPER_H
#define TXT_HELPER_H

#include <QString>
#include <QFile>
#include <QStringList>
#include <QDir>


namespace Lis {
    class Txt_helper
    {
    public:
        Txt_helper();
        QString get_line_from_file(const QString &pattern, QFile *file);
        QString get_data_from_line(const QString &pattern, const QString line);
        bool replace_line(const QString &pattern,const QString newline, QFile *source,QFile *temp);
        QString copy_lines(QFile *destination,QFile *source, const QString &startpattern =NULL,const QString &pattern =NULL);//pattern - шаблон строки ниже которой начнется копирование
        QString get_last_line(QFile *file);
        QString convert_date_to_file_name(const QString date);
        QStringList get_files_list_from_dir(const QString dir,const QString borderFile = NULL);
        void copy_files_to_file (QFile *destination, const QString sourceDir, QStringList *sourcefileList);
        void copy_pattern_lines_from_file_to_file_no_repeat(QFile *destination,QFile *source,QString startline, QString pattern);
    };
}
#endif // TXT_HELPER_H
