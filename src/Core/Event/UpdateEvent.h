#ifndef ___UPDATEEVENT_H___
#define ___UPDATEEVENT_H___

#include "Core/Event/Event.h"

class UpdateEvent : public Event {
public:
    virtual EventType Type() const { return EventType::Update; }

public:
    float DeltaTime = 0;
};

#endif // ___UPDATEEVENT_H___