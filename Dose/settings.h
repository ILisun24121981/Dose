#ifndef SETTING_EXTRACTOR_H
#define SETTING_EXTRACTOR_H
#include <QString>
#include <QVector>

namespace Lis {

    class Settings
    {
        public:
            Settings();
            QString read();

            //QVector<QString>
            QString _settings;
    };

}


#endif // SETTING_EXTRACTOR_H
