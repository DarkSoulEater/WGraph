#ifndef ___SEEKER_H___
#define ___SEEKER_H___

#include "Core/Event/Event.h"

class Seeker {
public:
    // Seeker();
    virtual ~Seeker() {};

    virtual void OnEvent(Event* event) = 0;
};

#endif // ___SEEKER_H___