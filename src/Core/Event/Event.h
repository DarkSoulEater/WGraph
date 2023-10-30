#ifndef ___EVENT_H___
#define ___EVENT_H___

#include "Core/Event/EventType.h"
#include <iostream>

class Event {
public:
    Event() {}
    virtual ~Event() {}
    virtual EventType Type() const { return EventType::None; }

    static std::string_view ToString(EventType event_type);
    virtual void Dump() const { std::cerr << "[" << ToString(Type()) << "]" << "\n"; }
};

int GetUniqueUserType();
int GetUniqueUIType();

#endif // ___EVENT_H___