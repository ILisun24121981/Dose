#ifndef TXT_LOGIN_PROCESSOR_H
#define TXT_LOGIN_PROCESSOR_H

#include<QString>
#include "Enums.h"

namespace Lis {

    //Класс стратегии авторизации.
    //Экземпляр данного класса создается в конструкторе экземпляра login Form класса
    //и выступает в качестве стратегии выполнения авторизации.

    class Txt_login_processor
    {

    public:

        Txt_login_processor();
        Lis::Verification_result verify(QString username, QString passwprd );

    };

}

#endif // TXT_LOGIN_PROCESSOR_
