#include "AtomBox.h"
#include <assert.h>
#include "EmitGase/Atom.h"
#include "EmitGase/SimpleAtom.h"
#include "EmitGase/DifficultAtom.h"
#include "EmitGase/Event/CapMoveEvent.h"
#include "EmitGase/Event/TemperatureChangeEvent.h"
#include "EmitGase/Explosion.h"

AtomBox::AtomBox(Vector2 position, Vector2 size) : box_(size), piston_(size) {
    effects_.SetParent(this);
    gases_.SetParent(this);
    piston_.SetParent(this);
    position_ = position;
    Produce();
}

void AtomBox::OnEvent(const Event *event) { 
    if (event->Type() == EventType(kUserEventMoveCap)) {
        OnMoveCapEvent(*static_cast<const CapMoveEvent*>(event));
    } else if (event->Type() == EventType(kUserEventCollisionWall)) {
        OnCollisionWallEvent(*static_cast<const CollisionWall*>(event));
        return;
    } else if (event->Type() == EventType(kUserEventProduce)) {
        OnProduceEvent(*static_cast<const ProduceEvent*>(event));
        return;
    } else if (event->Type() == EventType::Update) {
        OnUpdateEvent(*static_cast<const UpdateEvent*>(event));
    } else if (event->Type() == EventType(kUserEventTemperatureChange)) {
        OnTemperatureChangeEvent(*static_cast<const TemperatureChangeEvent*>(event));
    } 

    Widget::OnEvent(event);
}

void AtomBox::OnDrawEvent(const DrawEvent &event) {
    box_.setOutlineThickness(4.f);
    box_.setFillColor(sf::Color(0, 0, 0, 100));
    box_.setOutlineColor(sf::Color(0, 0, 0, 200));
    box_.setPosition(sf::Vector2f(position_));

    event.Window.draw(box_);
}

void AtomBox::OnMoveCapEvent(const CapMoveEvent &event) {
    return; // Nothing
}

void AtomBox::OnCollisionWallEvent(const CollisionWall &event) {
    pressure_counter_ += event.Momentum;
}

void AtomBox::OnUpdateEvent(const UpdateEvent &event) {
    static float Timer = 0;
    Timer += event.DeltaTime;

    if (Timer >= 1.f) {
        Timer = 0;
        UpdatePressure();
    }

    gases_.CollisionChecking();
}

void AtomBox::OnProduceEvent(const ProduceEvent &event) {
    std::shared_ptr<Widget> atom;

    if (event.kAtomType == AtomType::Simple) {
        atom = gases_.AddWidget(new SimpleAtom({0, 0}, box_.getSize()));
    } else if (event.kAtomType == AtomType::Difficult) {
        atom = gases_.AddWidget(new DifficultAtom({0, 0}, box_.getSize()));
    } else if (event.Explosion.has_value()) {
        assert(event.Position.has_value() && "Explosion must have position\n");
        ProduceExplosion(event.Explosion.value(), event.Position.value());
        return;
    } else {
        return;
    }

    CapMoveEvent cm_event(piston_.GetPosition().Y + piston_.GetThickness());
    atom->OnEvent(&cm_event);

    TemperatureChangeEvent temp_event(temperature_);
    atom->OnEvent(&temp_event);

    if (event.Position.has_value()) {
        atom->SetPosition(event.Position.value());
    }
}

void AtomBox::OnTemperatureChangeEvent(const TemperatureChangeEvent &event) {
    UpdateTemperature(event.Temperature);
}

void AtomBox::UpdateTemperature(float new_temperature) {
    temperature_ = new_temperature;
}

void AtomBox::Produce() {
    return;
    for (int i = 0; i < 10; ++i) {
        auto atom = gases_.AddWidget(new SimpleAtom({0, 0}, box_.getSize()));

        CapMoveEvent cm_event(piston_.GetPosition().Y + piston_.GetThickness());
        atom->OnEvent(&cm_event);

        TemperatureChangeEvent temp_event(temperature_);
        atom->OnEvent(&temp_event);
    }

    for (int i = 0; i < 0; ++i) {
        auto atom = gases_.AddWidget(new DifficultAtom({0, 0}, box_.getSize()));

        CapMoveEvent cm_event(piston_.GetPosition().Y + piston_.GetThickness());
        atom->OnEvent(&cm_event);

        TemperatureChangeEvent temp_event(temperature_);
        atom->OnEvent(&temp_event);
    }
}

void AtomBox::ProduceExplosion(int count, Vector2 position) {
    for (int i = 0; i < count; ++i) {
        Vector2 dir(0, -1);
        int angle = rand() % 12;
        dir.Rotate(angle * 30);

        auto widget = gases_.AddWidget(new SimpleAtom({0, 0}, box_.getSize()));
        Atom* atom = static_cast<Atom*>(widget.get());
    
        atom->SetPosition(position + dir * atom->GetRadius() * 3.f);
        atom->SetDir(dir);

        CapMoveEvent cm_event(piston_.GetPosition().Y + piston_.GetThickness());
        atom->OnEvent(&cm_event);

        TemperatureChangeEvent temp_event(temperature_);
        atom->OnEvent(&temp_event);
    }

    auto explosion = effects_.AddWidget(new Explosion());
    explosion->SetPosition(position);
}

void AtomBox::UpdatePressure() {
    pressure_ = pressure_counter_ / 3;
}

void AtomBox::CollisionChecking() {

}
