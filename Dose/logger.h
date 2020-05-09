#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include "txt_logger.h"


namespace Lis {

    class Logger: public QObject, public Txt_logger
    {
        Q_OBJECT

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
