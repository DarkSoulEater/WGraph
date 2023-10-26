#ifndef ___KEYEVENT_H___
#define ___KEYEVENT_H___

#include "Core/Event/Event.h"
#include "SFML/Graphics.hpp"

using KeyCode = sf::Keyboard;

class KeyEvent : public Event {
public:
    KeyEvent() {}

    virtual EventType Type() const override { return EventType::Key; }

public:
    struct Key {
        bool Pressed = false;
        bool Released = false;
    };

    static const int kKeyCount = 101;

    Key Keys[kKeyCount];
};

#endif // ___KEYEVENT_H___