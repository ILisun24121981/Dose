#ifndef TXT_LOGGER_H
#define TXT_LOGGER_H

#include <QObject>
#include <QString>
#include <QStringList>


namespace Lis {
    class Txt_logger:public QObject
    {

        Q_OBJECT

    public:
        Txt_logger();
        QStringList* find_last_updated_point_data(QString reportName);

    private:
        QString _logFileLink;
    };
}

#endif // TXT_LOGGER_H
