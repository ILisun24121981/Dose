#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow_processor.h"

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
        Ui::MainWindow *ui;
        MainWindow_processor *_mw_processor;
        QString User;
};

#endif // MAINWINDOW_H
