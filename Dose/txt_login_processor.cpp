#include "txt_login_processor.h"
#include "settings.h"
#include <QDebug>
#include <QFile>
#include <QRegExp>
#include "QMessageBox"

Lis::Txt_login_processor::Txt_login_processor()
{

}

Lis::Login_processor::Verification_result Lis::Txt_login_processor::check_account(QString username,QString password){
    QFile loginfile(Settings::get_instance()->get(Settings::Setting_name::File_to_store_users_logins_and_passports));
    if (!loginfile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(NULL, QObject::tr("Error"),"Passport_file_problem");
        return Login_processor::Verification_result::Verification_problem;
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
                    return Login_processor::Verification_result::Verification_Passed;
                }else{
                    return Login_processor::Verification_result::Password_is_not_correct;
                }
                match =1;
            }
        }
        if(match ==0){
            return Login_processor::Verification_result::Login_is_not_correct;
        }
    }
}
