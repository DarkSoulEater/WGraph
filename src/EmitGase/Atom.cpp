#include "Atom.h"
#include <assert.h>
#include <cmath>
#include "EmitGase/Event/CollisionWall.h"

Atom::Atom(Vector2 box_position, Vector2 box_size) 
            : left_bound_ (box_position.X),              upper_bound_ (box_position.Y),
              right_bound_(box_position.X + box_size.X), bottom_bound_(box_position.Y + box_size.Y) {
    SetBoundsSize(Vector2(2 * radius_)); 
    position_ = Vector2(rand() % (int)(right_bound_ - radius_) + radius_, 
                        rand() % (int)(bottom_bound_ - radius_) + radius_);
    dir_ = Vector2::Normalize(Vector2((rand() % 100) / 100.f, (rand() % 100) / 100.f));
}

void Atom::SetMass(float mass) {
    mass_ = mass;
    UpdateSpeed();
}

void Atom::OnEvent(const Event *event)
{
    if (!is_enabled) return;
    if (event->Type() == EventType::Update) {
        OnUpdateEvent(*static_cast<const UpdateEvent*>(event));
    } else if (event->Type() == EventType(kUserEventMoveCap)) {
        OnMoveCapEvent(*static_cast<const CapMoveEvent*>(event));
        return;
    } else if (event->Type() == EventType(kUserEventTemperatureChange)) {
        OnTemperatureChangeEvent(*static_cast<const TemperatureChangeEvent*>(event));
        return;
    }

    Widget::OnEvent(event);
}

void Atom::OnUpdateEvent(const UpdateEvent &event) {
    assert(GetParent() && "Atom must have parent\n");

    position_ += dir_ * speed_ * event.DeltaTime;

    CollisionWall wall_event(mass_ * speed_ * speed_ / 2.0f);
    Object* box = GetParent()->GetParent();
    assert(box && "Atom parent must have parent\n");

    if (position_.X - radius_ <= left_bound_) {
        dir_ = Vector2::Reflect(dir_, Vector2(1, 0));
        position_.X = left_bound_ + radius_;
        box->OnEvent(&wall_event);
    } else if (position_.X + radius_ >= right_bound_) {
        dir_ = Vector2::Reflect(dir_, Vector2(-1, 0));
        position_.X = right_bound_ - radius_;
        box->GetParent()->OnEvent(&wall_event);
    }

    if (position_.Y - radius_ <= upper_bound_) {
        dir_ = Vector2::Reflect(dir_, Vector2(0, 1));
        position_.Y = upper_bound_ + radius_;
        box->GetParent()->OnEvent(&wall_event);
    } else if (position_.Y + radius_ >= bottom_bound_) {
        dir_ = Vector2::Reflect(dir_, Vector2(0, -1));
        position_.Y = bottom_bound_ - radius_;
        box->GetParent()->OnEvent(&wall_event);
    }
}

void Atom::OnMoveCapEvent(const CapMoveEvent &event) {
    upper_bound_ = event.NewUpperButtom;
}

void Atom::OnTemperatureChangeEvent(const TemperatureChangeEvent &event) {
    temperature_ = event.Temperature;
    UpdateSpeed();
    // std::cout << speed_ << "\n";
}

void Atom::OnDrawEvent(const DrawEvent &event) {
    DrawBounds(event);
}

void Atom::DrawBounds(const DrawEvent &event) {
    sf::RectangleShape bounds(bounds_size_);
    bounds.setPosition(MapToGlobal());
    bounds.setOrigin(GetOrigin());

    bounds.setOutlineColor(sf::Color::Red);
    bounds.setOutlineThickness(1.f);

    bounds.setFillColor(sf::Color(0,0,0,0));

    event.Window.draw(bounds);
}

void Atom::UpdateSpeed() {
    speed_ = std::sqrt(3.f * kBoltzmann * temperature_ / mass_);
}
