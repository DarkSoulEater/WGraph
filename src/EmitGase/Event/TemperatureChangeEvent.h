#ifndef ___TEMPERATURECHANGEEVENT_H___
#define ___TEMPERATURECHANGEEVENT_H___

#include "Core/Event/Event.h"

const int kUserEventTemperatureChange = (int)(EventType::User) + 2;

class TemperatureChangeEvent : public Event {
public:
    TemperatureChangeEvent(float temperature = 0) : Temperature(temperature) {}
    
    virtual EventType Type() const { return EventType(kUserEventTemperatureChange); }
public:
    float Temperature; 
};

#endif // ___TEMPERATURECHANGEEVENT_H___