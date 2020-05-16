#ifndef TRASH_CLEANER_H
#define TRASH_CLEANER_H

#include <QObject>

//класс создан как накопитель мусора
//экземпляр создается в функциях, а остальные объекты с предком QObject
//создаются в динамической памяти и в качестве параметра patent при создании
//принимают экземпляр данного класса
//по завершению работы функции данный объект уничтожается и , в соответствии
//c логикой Qt уничтожает все обьекты child (те кому он был передан в качестве parent)


class Trash_cleaner:public QObject
{
    Q_OBJECT
public:
    Trash_cleaner(QObject *parent =nullptr);
};

#endif // TRASH_CLEANER_H
