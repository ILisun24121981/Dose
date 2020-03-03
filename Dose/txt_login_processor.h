#ifndef TXT_LOGIN_PROCESSOR_H
#define TXT_LOGIN_PROCESSOR_H
#include<QString>


namespace Lis {

    class Txt_login_processor
    {

    public:
        enum Verification_result {
            Verification_Passed,
            Passport_file_problem,
            No_such_user,
            Password_not_correct
        };

        Txt_login_processor();
        Verification_result check_account(QString username, QString passwprd );

    };

}

#endif // TXT_LOGIN_PROCESSOR_H
