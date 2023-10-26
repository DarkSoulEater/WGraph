#ifndef ___CAPMOVEEVENT_H___
#define ___CAPMOVEEVENT_H___

#include "Core/Event/Event.h"

const int kUserEventMoveCap = (int)(EventType::User) + 1;

class CapMoveEvent : public Event {
public:
    CapMoveEvent() {}
    CapMoveEvent(float new_upper_buttom) : NewUpperButtom(new_upper_buttom) {}
    virtual EventType Type() const override { return EventType(kUserEventMoveCap); }

public:
    float NewUpperButtom = 0;
};

#endif // ___CAPMOVEEVENT_H___