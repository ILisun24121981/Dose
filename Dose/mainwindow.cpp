#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(Controller *ct,QWidget *parent )
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    ui->label_UserName->setText(ct->_username);
    _repMng = new Report_manager(ct,this);
    qDebug()<< "MW created";   
    connection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connection(){
    QObject::connect(ui->btn_UpdComRawRep,SIGNAL(clicked()),this->_repMng,SLOT(update_common_raw_report()));
}
