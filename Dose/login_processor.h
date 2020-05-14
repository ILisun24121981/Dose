#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include "processor.h"
#include "Enums.h"
#include "txt_login_processor.h"
#include "eventfilter_login_form.h"

namespace Lis {


    class Login_processor:public Processor//класс бизнесс логики
    {
        //Класс предназначен для связи выполнение бизнес действий (авторизации).
        //Login_processor  - класс бизнесс логики и не требует изменений при переходе ,например к работе с базой данных
        //для данного перехода необходимо реализовать класс стратегии, например, SQL_login_processor
        //в котором реализовать метод check_account возвращающий результат типа Verification_result
        //и создать/добавить его экземпляр в свойство _strategy.

        Q_OBJECT


        public:

            Login_processor(Controller *ct);
            ~Login_processor();


            Txt_login_processor *_strategy;

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
