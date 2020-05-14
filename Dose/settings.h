#ifndef SETTING_EXTRACTOR_H
#define SETTING_EXTRACTOR_H
#include <QString>
#include <QVector>
#include "Enums.h"

namespace Lis {

    class Settings
    {
        public:           

            static Settings* get_instance();
            QString get(Setting_name);
             ~Settings();

            bool _initResult;

        private:

            Settings();
            static Settings *_instance;
            bool init();

            QVector<QString> *_settings;

    };
}


#endif // SETTING_EXTRACTOR_H
