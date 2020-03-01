#ifndef SETTING_EXTRACTOR_H
#define SETTING_EXTRACTOR_H
#include <QString>
#include <QVector>

namespace Lis {

    class Settings
    {
        public:

            enum Setting_name {
                File_to_store_users_logins_and_passports,
                Folder_to_search_common_reports,
                Folder_to_store_personal_reports,
                File_to_store_logs
            };

            static Settings* getInstance();
            QString get(Setting_name);
             ~Settings();

            bool _initResult;

        private:

            Settings();
            static Lis::Settings *_instance;
            bool Init();

            QVector<QString> *_settings;

    };
}


#endif // SETTING_EXTRACTOR_H
