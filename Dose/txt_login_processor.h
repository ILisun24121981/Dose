#ifndef TXT_LOGIN_PROCESSOR_H
#define TXT_LOGIN_PROCESSOR_H

#include<QString>
#include "login_processor.h"

namespace Lis {

    class Txt_login_processor
    {

    public:

        Txt_login_processor();
        Login_processor::Verification_result check_account(QString username, QString passwprd );

    };

}

#endif // TXT_LOGIN_PROCESSOR_
