#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include <QFileSystemModel>
#include "processor.h"
#include "login_form.h"

namespace Lis {

    class Loginner:public Processor
    {
        Q_OBJECT
        public:
            Loginner(Login_form *parent);
            ~Loginner();

        public slots:
            void loginCheck(QString username,QString password);
        public:
            Login_form *_parent;
     };

} //namespace Lis


#endif // LOGINNER_H
