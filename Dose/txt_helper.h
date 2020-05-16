#ifndef TXT_HELPER_H
#define TXT_HELPER_H

#include <QString>
#include <QRegExp>
#include <QFile>

class Txt_helper
{
public:
    Txt_helper();
    QString find_line_in_file(const QString &pattern, QFile *file);
    QString find_data_in_line(const QString &pattern, QString line);
};

#endif // TXT_HELPER_H
