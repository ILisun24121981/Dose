#ifndef REPORT_UPDATER_H
#define REPORT_UPDATER_H

#include "QFile"
#include "controller.h"
#include "processor.h"


namespace Lis {
    class Report_updater
    {

        public:
            void update_common_raw_report();
            void update_personal_raw_reports();            

        private:
            QStringList* get_login_list();

    };
}

#endif // I_REPORT_UPDATER_H
