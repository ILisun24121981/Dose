#ifndef TRASH_CLEANER_H
#define TRASH_CLEANER_H

#include <QObject>

class Trash_cleaner:public QObject
{
    Q_OBJECT
public:
    Trash_cleaner(QObject *parent =nullptr);
};

#endif // TRASH_CLEANER_H
