#ifndef TXT_LOGGER_H
#define TXT_LOGGER_H

#include <QString>

namespace Lis {
    class Txt_logger
    {
    public:
        Txt_logger();
        void check_log_file();
        QString find_last_update_time_date();
    };
}

#endif // TXT_LOGGER_H
