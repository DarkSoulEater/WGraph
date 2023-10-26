#include "Event.h"
#include "assert.h"

std::string_view Event::ToString(EventType event_type) {
    #define DefineEventType(NAME, CODE)     \
        case EventType::NAME: {             \
            return std::string_view(#NAME); \
        } break;                            \

    switch (event_type) {
        #include "Core/Event/EnumType.def"

        default: {
            return std::string_view("Unknow");
        } break;
    }
}

int GetUniqueUserType() {
    static int FreeUserType_ = (int)EventType::User + 1;
    assert(FreeUserType_ < (int)EventType::MaxUser);
    return FreeUserType_++;
}

int GetUniqueUIType() {
    static int FreeUIType_ = (int)EventType::UI + 1;
    assert(FreeUIType_ < (int)EventType::MaxUI);

    return FreeUIType_++;
}
