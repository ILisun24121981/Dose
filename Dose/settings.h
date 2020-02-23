#ifndef SETTING_EXTRACTOR_H
#define SETTING_EXTRACTOR_H
#include <QString>
#include <QVector>

namespace Lis {

    class Settings
    {
        public:

            enum Setting_name {
                Folder_to_search_common_reports,
                Folder_to_store_personal_reports,
                Folder_to_store_logs
            };

            Settings();
            ~Settings();
            bool read();

            bool result;
            QVector<QString> *_settings;
    };
}


#endif // SETTING_EXTRACTOR_H
