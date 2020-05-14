#include "mainwindow_processor.h"

Lis::MainWindow_processor::MainWindow_processor(Controller *ct):Processor(ct){
    connection();
    _repManager = new Report_manager(ct);
}

Lis::MainWindow_processor::~MainWindow_processor(){

}

void Lis::MainWindow_processor::connection(){

}
