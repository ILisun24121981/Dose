#ifndef CHART_WIDGET_H
#define CHART_WIDGET_H

#include <QWidget>
#include <QtCharts/QChartGlobal>
#include "chart_item.h"
#include "data_model.h"



QT_CHARTS_BEGIN_NAMESPACE
class QChart;
QT_CHARTS_END_NAMESPACE

namespace Ui {
class Chart_Widget;
}

QT_CHARTS_USE_NAMESPACE

namespace Lis {



    class Chart_Widget : public QWidget
    {
        Q_OBJECT

    public:
        explicit Chart_Widget(QWidget *parent = nullptr);
        ~Chart_Widget();

        Chart_Item* create_Chart_Item();
        DATA get_data();

    private:
        Ui::Chart_Widget *ui;
        DATA data;


    };

}

#endif // CHART_WIDGET_H