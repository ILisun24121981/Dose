#ifndef DATA_MODEL_H
#define DATA_MODEL_H
#include <QString>
#include <QFile>
#include <QDir>
#include "Enums.h"


namespace Lis {

//    typedef struct{
//        QString DateTime;
//        QList<float> values;
//    }TIME_POINT;

    typedef QPair <QString,QList<float>> TIME_POINT;

//    typedef struct{
//        QString UserName;
//        QList <TIME_POINT> TimeList;
//    }USER_POINTS;

    typedef QPair <QString,QList <TIME_POINT>> USER_POINTS;

    typedef QList<USER_POINTS> DATA;


    class Data_Model
    {
    public:
        Data_Model();
        TIME_POINT get_time_point(QString line);
        USER_POINTS get_user_points(QFile* personal_report);
        Lis::DATA get_data();

    };

}

#endif // DATA_MODEL_H
