#ifndef ___EVENTTYPE_H___
#define ___EVENTTYPE_H___

#include <string>

#define DefineEventType(NAME, CODE) NAME = CODE,
enum class EventType {
    #include "Core/Event/EnumType.def"
};

#endif // ___EVENTTYPE_H___