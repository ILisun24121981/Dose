#ifndef CHART_WIDGET_H
#define CHART_WIDGET_H

#include <QWidget>
#include <QtCharts/QChartGlobal>



QT_CHARTS_BEGIN_NAMESPACE
class QChart;
QT_CHARTS_END_NAMESPACE

namespace Ui {
class Chart_Widget;
}

QT_CHARTS_USE_NAMESPACE

class Chart_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Chart_Widget(QWidget *parent = nullptr);
    ~Chart_Widget();

private:
    Ui::Chart_Widget *ui;


};

#endif // CHART_WIDGET_H
