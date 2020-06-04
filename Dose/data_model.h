#ifndef DATA_MODEL_H
#define DATA_MODEL_H
#include <QString>
#include <QFile>
#include <QDir>
#include "Enums.h"


namespace Lis {

    enum Need_pos{
        TIME,
        Start =5,
        END =8
    };


    typedef QPair <QString,QList<float>> TIME_POINT;//время и параметры

    typedef QPair <QString,QList <TIME_POINT>> USER_POINTS;//имя пользователя и список TIME_POINT

    typedef QPair<QList<QString>,QList<USER_POINTS>> DATA;//список названий параметров и список USER_POINTS


    class Data_Model
    {
        public:
            Data_Model();
            float get_value_from_point(int pos);
            USER_POINTS get_user_points(QString username);
            Lis::DATA get_data();

            template<typename T>
            QList<T> get_parameters_from_line(int from, int to, const QString line);

        private:
            DATA _data;

    };

}

#endif // DATA_MODEL_H
