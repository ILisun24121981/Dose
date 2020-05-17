#ifndef TXT_HELPER_H
#define TXT_HELPER_H

#include <QString>
#include <QFile>


namespace Lis {
    class Txt_helper
    {
    public:
        Txt_helper();
        QString find_line_in_file(const QString &pattern, QFile *file);
        QString find_data_in_line(const QString &pattern, QString line);
        bool replace_line(const QString &pattern,const QString newline, QFile *source,QFile *temp);
        QString copy_lines(QFile *destination,QFile *source, const QString &pattern =NULL);//pattern - шаблон строки ниже которой начнется копирование
    };
}
#endif // TXT_HELPER_H
