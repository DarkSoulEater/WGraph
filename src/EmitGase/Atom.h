#ifndef ___ATOM_H___
#define ___ATOM_H___

#include "UI/Widget.h"
#include "Core/Event/UpdateEvent.h"
#include "EmitGase/Event/CapMoveEvent.h"
#include "EmitGase/Event/TemperatureChangeEvent.h"

enum class AtomType {
    None,
    Simple,
    Difficult
};

class Atom : public Widget {
public:
    Atom(Vector2 box_position, Vector2 box_size);
    virtual ~Atom() {}

    virtual AtomType Type() { return AtomType::None; }

    float GetRadius() const { return radius_; }
    float GetSpeed()  const { return speed_;  }
    Vector2 GetDir()  const { return dir_;    }
    float GetMass()   const { return mass_;   }

    void SetMass(float mass);
    void SetDir(Vector2 dir) { dir_ = Vector2::Normalize(dir); }

    virtual void OnEvent(const Event* event) override;

    virtual void OnUpdateEvent(const UpdateEvent& event);
    void OnMoveCapEvent(const CapMoveEvent &event);
    void OnTemperatureChangeEvent(const TemperatureChangeEvent& event);

    virtual void OnDrawEvent(const DrawEvent& event) override;

    void DrawBounds(const DrawEvent &event);

protected:
    float temperature_ = 0.f;
    void UpdateSpeed();

protected:
    float upper_bound_  = 0;
    float bottom_bound_ = 0;
    float left_bound_   = 0;
    float right_bound_  = 0;

    Vector2 dir_ = Vector2::Normalize(Vector2(1.f));
    float speed_ = 0.f;
    float radius_ = 15.f;
    float mass_ = kDefMass;

public:
    static constexpr float kDefMass = 1e-24f;
    static constexpr float kBoltzmann = 1380649e-29f;
};

#endif // ___ATOM_H___