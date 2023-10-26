#ifndef ___DRAWEVENT_H___
#define ___DRAWEVENT_H___

#include "Core/Event/Event.h"
#include "SFML/Graphics.hpp"
#include "Math/Vector2i.h"

class DrawEvent : public Event {
public:
    DrawEvent(sf::RenderWindow& window) : Window(window) {}
    virtual EventType Type() const override { return EventType::Draw; }

public:
    sf::RenderWindow& Window;
    float DrawDeltaTime = 0.f;
};

#endif // ___DRAWEVENT_H___