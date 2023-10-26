#ifndef ___ACDEBUG_H___
#define ___ACDEBUG_H___

#include <iostream>
#include "Core/Action/Action.h"

class AcDebug : public Action {
public:
    virtual void operator()() override {
        std::cerr << "Is Debug Action\n";
    }
};

#endif // ___ACDEBUG_H___