#ifndef ___TOOLCHANGEDEVENT_H___
#define ___TOOLCHANGEDEVENT_H___

#include "Core/Event/Event.h"

extern const int kUserEventToolChanged;

class ToolChangedEvent : public Event {
public:
    ToolChangedEvent() {}

    virtual EventType Type() const override;
};

#endif // ___TOOLCHANGEDEVENT_H___