#ifndef ___ATOMBOX_H___
#define ___ATOMBOX_H___

#include "SFML/Graphics.hpp"
#include "Core/Window.h"
#include "Core/Event/UpdateEvent.h"
#include "UI/Widget.h"
#include "EmitGase/AtomHandler.h"
#include "EmitGase/Piston.h"
#include "EmitGase/Event/CapMoveEvent.h"
#include "EmitGase/Event/CollisionWall.h"
#include "EmitGase/Event/ProduceEvent.h"
#include "EmitGase/Event/TemperatureChangeEvent.h"

class AtomBox : public Widget {
public:
    AtomBox(Vector2 position, Vector2 size);
    ~AtomBox() = default;

    virtual void OnEvent(const Event* event) override;

private:
    virtual void OnDrawEvent(const DrawEvent& event) override;
    void OnMoveCapEvent(const CapMoveEvent& event);
    void OnCollisionWallEvent(const CollisionWall& event);
    void OnUpdateEvent(const UpdateEvent& event);
    void OnProduceEvent(const ProduceEvent& event);
    void OnTemperatureChangeEvent(const TemperatureChangeEvent& event);

public:
    float GetTemperature() const { return temperature_; }
    void UpdateTemperature(float new_temperature);

    void Produce();
    void ProduceExplosion(int count, Vector2 position);

    float GetPressure() const { return pressure_; }
private:
    sf::RectangleShape box_;
    Piston piston_;

    float temperature_ = 0;

private:
    AtomsHandler gases_;
    WidgetsHandler effects_;

private:
    float pressure_counter_ = 0.f;
    float pressure_ = 0.f;

    void UpdatePressure();

private:
    void CollisionChecking();
};

#endif // ___ATOMBOX_H___