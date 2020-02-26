#include "txt_login_processor.h"
#include "settings.h"
#include <QDebug>
#include <QFile>
#include <QRegExp>

Lis::Txt_login_processor::Txt_login_processor()
{

}

Lis::Txt_login_processor::Verification_result Lis::Txt_login_processor::Check_Account(QString username,QString password){
    QFile loginfile(Lis::Settings::get(Lis::Settings::Setting_name::File_to_store_users_logins_and_passports));
    if (!loginfile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return Passport_file_problem;
    }else{
        qDebug()<<"file opened";
        QTextStream in(&loginfile);
        char match =0;
        while (!in.atEnd()&& match ==0 ) {
            QString line = in.readLine();
            QRegExp name("^name:"+username+".*$");
            if (name.exactMatch(line)){
                QRegExp pass(".*password:"+password+"$");
                if (pass.exactMatch(line)){
                    return Verification_Passed;
                }else{
                    return Password_not_correct;
                }
                match =1;
            }
        }
        if(match ==0){
            return No_such_user;
        }
    }
}
