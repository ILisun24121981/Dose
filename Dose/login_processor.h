#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include "processor.h"


namespace Lis {

    class Login_processor:public Processor
    {

        Q_OBJECT

        public:

        enum Login_failure_reason {
            Passport_file_problem,
            No_such_user,
            Password_not_correct
        };

            Login_processor(Controller *ct);
            ~Login_processor();
            void connection();

        public slots:
            void loginCheck(QString username,QString password);

        signals:
            void LoginFailed(Login_failure_reason reason);
            void LoginSuccessfull();

     };

} //namespace Lis


#endif // LOGINNER_H
