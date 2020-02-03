#include "processor.h"

Lis::Processor::Processor(Controller *ct, QObject *parent):QObject(parent)
{
    _controller = ct;
   // connect();
}

//void Lis::Processor::connect(){
//    this->
//    QObject::connect(this,SIGNAL(changeAppByController()),this->_controller,SLOT(changeApp()));
//}
