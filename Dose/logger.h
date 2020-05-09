#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include "txt_logger.h"


namespace Lis {

    class Logger: public Txt_logger
    {

        public:
            Logger();
            ~Logger();


        public slots:
           void write_login_history(QString username);
           QString find_time_date_of_last_update();
       // private:

    };

};
#endif // LOGGER_H
