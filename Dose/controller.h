#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include "processor.h"

namespace Lis {

    class Controller
    {
        public:
            Controller();
            ~Controller();
        public:
            QWidget *_widget;
            Processor *_pr;
    };

}// namespace Lis
#endif // CONTROLLER_H
