#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include "processor.h"
#include "txt_login_processor.h"



namespace Lis {

    class Login_processor:public Processor,Txt_login_processor//класс бизнесс логики
    {
        //Login_processor  - класс бизнесс логики и не требует изменений при переходе ,например к работе с базой данных
        //для данного перехода необходимо отнаследовать от него класс, например, SQL_login_processor
        //в котором реализовать метод check_account возвращающий результат типа Verification_result

        Q_OBJECT

        public:
            enum Verification_result {
                Verification_problem,
                Verification_Passed,
                Login_is_not_correct,
                Password_is_not_correct
            };

            Login_processor(Controller *ct);
            ~Login_processor();
            void connection();

           Verification_result _verResult;

        public slots:
            void verify_login(QString username,QString password);//connected to Login_form::login(QString userName,QString password)

        signals:
            void verification_failed(Lis::Login_processor::Verification_result res);//connected to Login_form::indicate_fail_reason(Lis::Login_processor::Verification_result)
            void verification_passed(QString username);//connected to Controller::autorisation_passed(QString)

     };

} //namespace Lis


#endif // LOGINNER_H
