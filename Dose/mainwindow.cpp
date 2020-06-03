#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chart_widget.h"
#include "data_model.h"
#include <QDebug>


MainWindow::MainWindow(Controller *ct,QWidget *parent )
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    ui->label_UserName->setText(ct->_username);



    qDebug()<< "MW created";   
    connection();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connection(){
    QObject::connect(ui->btn_UpdComRawRep,SIGNAL(clicked()),this,SLOT(update_common_raw_report()));
    QObject::connect(ui->btn_UpdPerRawReps,SIGNAL(clicked()),this,SLOT(update_personal_raw_reports()));
    QObject::connect(ui->btn_DataModel,SIGNAL(clicked()),this,SLOT(update_data_model()));
}

void MainWindow::update_common_raw_report(){
    Lis::Report_updater repM;
    repM.update_common_raw_report();
}
void MainWindow::update_personal_raw_reports(){
    Lis::Report_updater repM;
    repM.update_personal_raw_reports();
}
void MainWindow::update_data_model(){
    Data_Model model;
    model.get_data();

}
