#ifndef DATA_MODEL_H
#define DATA_MODEL_H
#include <QFile>
#include <QVector>

class Data_Model
{
    public:
        Data_Model();
        ~Data_Model();

    QVector<QFile*> Search_files();
    void Write_data_to_personal_files(QVector<QFile*> personal_files);
    void Read_data_from_file(QFile* file);
    void Write_data_to_file(QFile* file);

    public:
        QVector<QFile*> *_Personal_files;


};

#endif // DATA_MODEL_H
