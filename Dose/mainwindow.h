#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "report_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; };
QT_END_NAMESPACE

using namespace Lis;

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(Controller *ct = nullptr,QWidget *parent = nullptr);
        ~MainWindow();

    private:
        void connection();

        Ui::MainWindow *ui;       
        Report_manager *_repMng;
        QString User;
};

#endif // MAINWINDOW_H
