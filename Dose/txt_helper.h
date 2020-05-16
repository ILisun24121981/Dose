#ifndef TXT_HELPER_H
#define TXT_HELPER_H

#include <QString>
#include <QRegExp>
#include <QFile>


namespace Lis {
    class Txt_helper
    {
    public:
        Txt_helper();
        QString find_line_in_file(const QString &pattern, QFile *file);
        QString find_data_in_line(const QString &pattern, QString line);
        void copy_lines(QFile *destination,QFile *source, const QString *line =nullptr);//line - строка ниже которой начнется копирование
    };
}
#endif // TXT_HELPER_H
