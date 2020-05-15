#include "processor.h"

Lis::Processor::Processor(Controller *ct,QObject *parent):QObject(parent)
{
    _controller = ct;
}

Lis::Processor::~Processor(){

}


