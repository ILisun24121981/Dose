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
        QString find_line_in_file(const QString &pattern, QFile *file);
        QString find_data_in_line(const QString &pattern, const QString line);
        bool replace_line(const QString &pattern,const QString newline, QFile *source,QFile *temp);
        QString copy_lines(QFile *destination,QFile *source, const QString &pattern =NULL);//pattern - шаблон строки ниже которой начнется копирование
        QString get_last_line(QFile *file);
        QString convert_date_to_file_name(const QString date);
        QStringList* get_file_list(const QString dir,const QString borderFile =NULL);
        void copy_files_to_file (QFile *destination, const QString sourceDir, QStringList *sourcefileList);

    };
}
#endif // TXT_HELPER_H
