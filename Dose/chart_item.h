#ifndef CHART_ITEM_H
#define CHART_ITEM_H
#include <QDateTime>

#include <QGraphicsItem>

typedef struct {
    QDateTime datetime;
    float value;
}Point;



class Chart_Item:public QGraphicsItem
{
    public:
        Chart_Item(const QDateTime datetime,const float value);

    private:
        Point * _point;

};

#endif // CHART_ITEM_H
