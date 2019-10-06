#ifndef LOGINNER_H
#define LOGINNER_H

#include <QObject>
#include <QFileSystemModel>
#include "processor.h"

namespace Lis {

    class Loginner:public Processor
    {
        Q_OBJECT
        public:
            Loginner(QWidget *view);
            ~Loginner();

        public slots:
            void loginCheck(QString username,QString password);
        public:
            QWidget *_view;
     };

} //namespace Lis


#endif // LOGINNER_H
