#ifndef REPOR_MANAGER_H
#define REPOR_MANAGER_H

#include <QString>


namespace Lis {
    class Repor_manager
    {
        public:
            Repor_manager();
            void update_common_report();
            void update_personal_report(QString usarname);

    };
}

#endif // REPOR_MANAGER_H
