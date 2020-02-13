#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(Controller *ct,QWidget *parent )
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<< "1";
    ui->setupUi(this);
    qDebug()<< "2";
    ui->label_UserName->setText(ct->_username);
    qDebug()<< "MW created";
    _mw_processor = new MainWindow_processor(ct);
}

MainWindow::~MainWindow()
{
    delete ui;
}
