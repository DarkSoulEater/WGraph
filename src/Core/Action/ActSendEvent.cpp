#include "ActSendEvent.h"
#include <assert.h>
#include <iostream>

void ActSendEvent::operator()() { 
    assert(object_);
    // printf("Send event[%p] to object:id = %d [%p]\n", &event_, object_->Id(), object_);
    object_->OnEvent(event_.get()); 
}