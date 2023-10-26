#ifndef ___MOUSEEVENT_H___
#define ___MOUSEEVENT_H___

#include "Core/Event/Event.h"
#include "Math/Vector2i.h"

enum MouseButtom {
    kLeft,
    kRight,
    kMiddle
};

class MouseEvent : public Event {
public:
    MouseEvent() {}
    virtual ~MouseEvent() {};

    virtual EventType Type() const override { return EventType::Mouse; }

public:
    static const uint32_t kMouseButtonCount = 3;

    Vector2i MouseOldPosition = Vector2i(0, 0);
    Vector2i MousePosition    = Vector2i(0, 0);
    Vector2i DeltaMouse       = Vector2i(0, 0);

    struct Key {
        bool Pressed = false;
        bool Released = false;
    };
    
    Key MouseButton[kMouseButtonCount];

    int DeltaWheelScroll = 0;

    Key Shift;
    Key Ctrl;
    Key Alt;
};

#endif // ___MOUSEEVENT_H___