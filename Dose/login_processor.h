#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include "processor.h"
#include "txt_login_processor.h"


namespace Lis {

    class Login_processor:public Processor,public Txt_login_processor
    {

        Q_OBJECT

        public:        

            Login_processor(Controller *ct);
            ~Login_processor();
            void connection();

            Verification_result _result;

        public slots:
            void Verify_Login(QString username,QString password);

        signals:
            void Verification_Failed(Verification_result res);
            void Verification_Passed(QString username);

     };

} //namespace Lis


#endif // LOGINNER_H
