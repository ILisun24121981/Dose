#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "report_updater.h"

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

    private slots:
        void update_common_raw_report();
        void update_personal_raw_reports();
        void update_data_model();



    private:
        Ui::MainWindow *ui;
        QString User;
};

#endif // MAINWINDOW_H
