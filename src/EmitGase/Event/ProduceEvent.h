#ifndef ___PRODUCEEVENT_H___
#define ___PRODUCEEVENT_H___

#include <optional>
#include "Core/Event/Event.h"
#include "EmitGase/Atom.h"

const int kUserEventProduce = (int)(EventType::User) + 4;

class ProduceEvent : public Event {
public:
    ProduceEvent(AtomType type = AtomType::None) : kAtomType(type) {}

    virtual EventType Type() const override { return EventType(kUserEventProduce); }

public:
    AtomType kAtomType;
    float Mass = 0.f;
    std::optional<Vector2> Position;
    std::optional<int> Explosion;
};

#endif // ___PRODUCEEVENT_H___