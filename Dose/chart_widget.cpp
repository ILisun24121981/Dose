#include "chart_widget.h"
#include "chart_item.h"
#include "ui_chart_widget.h"
#include <QtCharts/QChart>
#include <QGraphicsView>
#include <QGraphicsScene>


Chart_Widget::Chart_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chart_Widget)
{
    ui->setupUi(this);

    QChart *chart;
    QGraphicsScene *scene;
    QList<Chart_Item*>* itemlist;



}

Chart_Widget::~Chart_Widget()
{
    delete ui;
}

//QChart* Chart_Widget::createScatterChart(QString ) const
//{
//    // scatter chart
//    QChart *chart = new QChart();
//    chart->setTitle("Scatter chart");
//    QString name("Series ");
//    int nameIndex = 0;
//    for (const DataList &list : m_dataTable) {
//        QScatterSeries *series = new QScatterSeries(chart);
//        for (const Data &data : list)
//            series->append(data.first);
//        series->setName(name + QString::number(nameIndex));
//        nameIndex++;
//        chart->addSeries(series);
//    }

//    chart->createDefaultAxes();
//    chart->axes(Qt::Horizontal).first()->setRange(0, m_valueMax);
//    chart->axes(Qt::Vertical).first()->setRange(0, m_valueCount);
//    // Add space to label to add space between labels and axis
//    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
//    Q_ASSERT(axisY);
//    axisY->setLabelFormat("%.1f  ");
//    return chart;
//}
