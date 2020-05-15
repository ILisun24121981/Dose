#ifndef I_TXT_LOGIN_H
#define I_TXT_LOGIN_H

#include<QString>
#include "Enums.h"

namespace Lis {

    //Интерфейс верификации логера их txt файла.

    class  I_Txt_login
    {    
        protected:
            Lis::Verification_result verify(QString username, QString passwprd );

    };



}

#endif // I_TXT_LOGIN
