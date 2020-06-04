#ifndef TXT_HELPER_H
#define TXT_HELPER_H

#include <QString>
#include <QFile>
#include <QStringList>
#include <QDir>
#include "chart_item.h"
#include "Enums.h"


namespace Lis {
    class Txt_helper
    {
    public:
        Txt_helper();

        QString get_line_from_file(const QString &pattern,QFile *file);
        QString get_last_line(QFile *file);
        QString copy_lines(QFile *destination,QFile *source, const QString &startpattern =NULL,const QString &pattern =NULL);
        QStringList get_files_list_from_dir(const QString dir,const QString borderFileName = NULL);
        void copy_files_to_file (QFile *destination, const QString sourceDir, const QStringList *sourcefileList);

//        bool replace_line(const QString &pattern,const QString newline, QFile *source,QFile *temp);

        QString get_matched_from_line(const QString &pattern, const QString line);
        QList<QString> get_all_matched_from_line(QString pattern, QString line);
        QString convert_date_format(const QString date);



    };
}
#endif // TXT_HELPER_H
