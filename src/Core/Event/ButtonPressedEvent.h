#ifndef ___BUTTONPRESSEDEVENT_H___
#define ___BUTTONPRESSEDEVENT_H___

#include "Core/Event/Event.h"
#include "UI/PushButton.h"

class ButtonPressedEvent : public Event {
public:
    ButtonPressedEvent(PushButton* button) : Button(button) {}

    virtual EventType Type() const { return EventType::ButtonPressed; }    
public:
    PushButton* Button = nullptr;
};

#endif // ___BUTTONPRESSEDEVENT_H___