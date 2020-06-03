#ifndef CHART_ITEM_H
#define CHART_ITEM_H
#include <QDateTime>

#include <QGraphicsItem>


namespace Lis {


    class Chart_Item:public QGraphicsItem
    {
        public:
            Chart_Item(const QDateTime datetime,const float value);

        private:
            //Chart_Point * _point;

    };
}

#endif // CHART_ITEM_H
