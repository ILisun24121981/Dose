#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include <QFileSystemModel>
#include "login_form.h"

namespace Lis {

    class Loginner:public QObject
    {
        Q_OBJECT

        public:
            Loginner(Login_form *lF);
            ~Loginner();

        public slots:
            void loginCheck(QString username,QString password);


        private:
            Login_form *_loginForm;

    };

} // namespace Lis


#endif // LOGINNER_H
