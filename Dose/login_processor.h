#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include "processor.h"
#include "controller.h"


namespace Lis {

    class Login_processor:public Processor
    {

        Q_OBJECT

        public:
            Login_processor(Controller *ct);
            ~Login_processor();


        public slots:
            void loginCheck(QString username,QString password);
     };

} //namespace Lis


#endif // LOGINNER_H
