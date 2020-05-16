#ifndef REPORT_MANAGER_H
#define REPORT_MANAGER_H

#include "QFile"
#include "controller.h"
#include "processor.h"


namespace Lis {
    class Report_manager:public Processor
    {
        Q_OBJECT


        public:
            Report_manager(Controller *ct, QObject *parent);

        public slots:
            void update_common_raw_report();


    };
}

#endif // REPORT_MANAGER_H
