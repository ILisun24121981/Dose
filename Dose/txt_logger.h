#ifndef TXT_LOGGER_H
#define TXT_LOGGER_H

#include <QString>
#include <QFile>

namespace Lis {
    class Txt_logger
    {
    public:
        Txt_logger();
        QString find_last_update_time_date();

    private:
        QFile *_logFile;
    };
}

#endif // TXT_LOGGER_H
