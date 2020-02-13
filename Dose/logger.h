#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>


namespace Lis {

    class Logger: public QObject
    {
        Q_OBJECT

        public:
            Logger();
            ~Logger();

        public slots:
           void write_login_history(QString username);

       // private:

    };

};
#endif // LOGGER_H
