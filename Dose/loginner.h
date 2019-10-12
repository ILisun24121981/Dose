#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include "processor.h"
#include "controller.h"
#include "login_form.h"


namespace Lis {

    class Loginner:public Processor
    {
        Q_OBJECT
        public:
            Loginner(Controller *ct);
            ~Loginner();

        public slots:
            void loginCheck(QString username,QString password);
            void connection();

     };

} //namespace Lis


#endif // LOGINNER_H
