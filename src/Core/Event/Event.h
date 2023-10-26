#ifndef ___EVENT_H___
#define ___EVENT_H___

#include "Core/Event/EventType.h"

class Event {
public:
    Event() {}
    virtual ~Event() {}
    virtual EventType Type() const { return EventType::None; }

    static std::string_view ToString(EventType event_type);
};

int GetUniqueUserType();
int GetUniqueUIType();

#endif // ___EVENT_H___