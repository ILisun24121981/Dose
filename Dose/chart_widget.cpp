#include "chart_widget.h"
#include "chart_item.h"
#include "ui_chart_widget.h"
#include <QtCharts/QChart>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "txt_helper.h"


Lis::Chart_Widget::Chart_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chart_Widget)
{
    ui->setupUi(this);

    QChart *chart;
    QGraphicsScene *scene;
    QList<Chart_Item*>* itemlist;


}

Lis::Chart_Widget::~Chart_Widget()
{
    delete ui;
}

Lis::Chart_Item* Lis::Chart_Widget::create_Chart_Item(){
    Txt_helper helper;

}
