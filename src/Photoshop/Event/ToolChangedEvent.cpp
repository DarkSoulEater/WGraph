#include "ToolChangedEvent.h"

const int kUserEventToolChanged = GetUniqueUserType();

EventType ToolChangedEvent::Type() const {
    return EventType(kUserEventToolChanged);
}
