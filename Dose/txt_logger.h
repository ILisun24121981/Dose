#ifndef TXT_LOGGER_H
#define TXT_LOGGER_H

#include <QObject>
#include <QString>
#include <QStringList>



namespace Lis {
    class Txt_logger:public QObject
    {

        Q_OBJECT

    public:
        Txt_logger();
        bool find_last_updated_line_data(const QString reportName,QString &fileData,QString &timeData);
        bool set_last_updated_line_data(const QString reportName, const QString fileData,const QString timeData);

    private:
        QString _logFileLink;
        QString _tempFileLink;
    };
}

#endif // TXT_LOGGER_H
