#ifndef ___BARSCROLLEDEVENT_H___
#define ___BARSCROLLEDEVENT_H___

#include "Core/Event/Event.h"
#include "UI/ScrollBar.h"

class BarScrolledEvent : public Event {
public:
    BarScrolledEvent(ScrollBar* bar, float value, float max_value) : Bar(bar), Value(value), MaxValue(max_value) {}

    virtual EventType Type() const { return EventType::BarScrolled; }    
public:
    ScrollBar* Bar = nullptr;
    float Value = 0.f;
    float MaxValue = 0.f;
};

#endif // ___BARSCROLLEDEVENT_H___