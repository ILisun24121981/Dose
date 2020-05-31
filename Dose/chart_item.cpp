#include "chart_item.h"

Chart_Item:: Chart_Item(const QDateTime datetime,const float value)
{
    _point->datetime = datetime;
    _point->value = value;
}

