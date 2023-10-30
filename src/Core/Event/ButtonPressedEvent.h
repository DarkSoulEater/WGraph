#ifndef ___BUTTONPRESSEDEVENT_H___
#define ___BUTTONPRESSEDEVENT_H___

#include "Core/Event/Event.h"
#include "UI/PushButton.h"

class ButtonPressedEvent : public Event {
public:
    ButtonPressedEvent(PushButton* button, int index = -1) : Button(button), Index(index) {}

    virtual EventType Type() const { return EventType::ButtonPressed; }    
public:
    PushButton* Button = nullptr;
    int Index = -1;
};

#endif // ___BUTTONPRESSEDEVENT_H___