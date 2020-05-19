#include "i_txt_login.h"
#include "settings.h"
#include <QDebug>
#include <QFile>
#include <QRegExp>
#include "QMessageBox"


Lis::Verification_result Lis::I_Txt_login::verify(QString username,QString password){
    QFile loginfile((Settings::get_instance()->get(Lis::Setting_name::Logins_and_passports_file_folder)+ "Login.txt"));
    if (!loginfile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(NULL, QObject::tr("Error"),"Passport_file_problem");
        return Verification_result::Verification_problem;
    }
    qDebug()<<"file opened";
    QTextStream in(&loginfile);
    char match =0;
    while (!in.atEnd()&& match ==0 ) {
        QString line = in.readLine();
        QRegExp name("^name:"+username+".*$");
        if (name.exactMatch(line)){
            QRegExp pass(".*password:"+password+"$");
            if (pass.exactMatch(line)){
                return Verification_result::Verification_Passed;
            }else{
                return Verification_result::Password_is_not_correct;
            }
            match =1;
        }
    }
    if(match ==0){
        return Verification_result::Login_is_not_correct;
    }

}
