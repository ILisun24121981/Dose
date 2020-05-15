#ifndef LOGINNER_H
#define LOGINNER_H

#include "processor.h"
#include "Enums.h"
#include "i_txt_login.h"


namespace Lis {


    class Login_processor:public Processor, public I_Txt_login
    {
        //Класс предназначен для связи выполнение бизнес действий (авторизации).
        //Login_processor  - класс бизнесс логики и не требует изменений при переходе ,например к работе с базой данных
        //для данного перехода необходимо реализовать интерфейс, например, I_SQL_login
        //в котором реализовать метод verify возвращающий результат типа Verification_result
        //и добавить его в качастве второго радителя к классу Login_processor.

        Q_OBJECT


        public:

            Login_processor(Controller *ct,QObject *parent);
            ~Login_processor();


        public slots:
            void verify_login(QString username,QString password);//connected to Login_form::login(QString userName,QString password)

        signals:
            void verification_failed(Verification_result res);//connected to Login_form::indicate_fail_reason(Lis::Login_processor::Verification_result)
            void verification_passed(QString username);//connected to Controller::autorisation_passed(QString)

        private:
            void connection();
     };

} //namespace Lis


#endif // LOGINNER_H
