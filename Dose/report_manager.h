#ifndef REPORT_MANAGER_H
#define REPORT_MANAGER_H

#include <QString>
#include <QObject>
#include "QFile"
#include "controller.h"


namespace Lis {
    class Report_manager:public QObject
    {
        Q_OBJECT


        public:
            Report_manager(Controller *ct);


        public slots:
            void update_common_raw_report();

        private:
            void connection();

            QFile *_comRawRep;

    };
}

#endif // REPORT_MANAGER_H
