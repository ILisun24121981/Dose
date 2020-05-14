#ifndef MAINWINDOW_PROCESSOR_H
#define MAINWINDOW_PROCESSOR_H

#include <QObject>
#include "processor.h"
#include "report_manager.h"

namespace Lis {

    class MainWindow_processor:public Processor
    {

        Q_OBJECT

        public:
            MainWindow_processor(Controller *ct);
            ~MainWindow_processor();

            Report_manager *_repManager;

       private:
            void connection();


    };
}
#endif // MAINWINDOW_PROCESSOR_H
