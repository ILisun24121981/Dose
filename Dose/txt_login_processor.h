#ifndef TXT_LOGIN_PROCESSOR_H
#define TXT_LOGIN_PROCESSOR_H

#include<QString>
#include "Enums.h"

namespace Lis {

    class Txt_login_processor
    {

    public:

        Txt_login_processor();
        Lis::Verification_result verify(QString username, QString passwprd );

    };

}

#endif // TXT_LOGIN_PROCESSOR_
