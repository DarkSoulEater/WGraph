#ifndef ___COLLISIONWALL_H___
#define ___COLLISIONWALL_H___

#include "Core/Event/Event.h"

const int kUserEventCollisionWall = (int)(EventType::User) + 3;

class CollisionWall : public Event {
public:
    CollisionWall(float momentum = 0.f) : Momentum(momentum) {}

    virtual EventType Type() const { return EventType(kUserEventCollisionWall); }
public:
    float Momentum = 0.f;
};

#endif // ___COLLISIONWALL_H___