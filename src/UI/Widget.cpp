#include "Widget.h"
#include <iostream>

// FloatRect Widget::GetLocalBounds() {
//     return FloatRect(position_, bounds_size_);
// }

void Widget::SetBoundsSize(const Vector2 &bounds_size, bool update_origin) {
    bounds_size_ = bounds_size;
    
    if (update_origin) {
        origin_ = bounds_size / 2;
    }
}

FloatRect Widget::GetGlobalBounds()
{
    Vector2 global_pos = MapToGlobal();
    return FloatRect(global_pos - GetOrigin(), bounds_size_);
}

void Widget::OnEvent(const Event *event)
{
    if (!is_enabled) return;

    if (event->Type() == EventType::Mouse) {
        OnMouseEvent(*static_cast<const MouseEvent*>(event));
    } else if (event->Type() == EventType::Draw) {
        OnDrawEvent(*static_cast<const DrawEvent*>(event));
    }

    Object::OnEvent(event);
}

void Widget::OnDrawEvent(const DrawEvent &event) {
    // Create bounds rect
    sf::RectangleShape bounds_rect = sf::RectangleShape(sf::Vector2f(bounds_size_));
    bounds_rect.setPosition(MapToGlobal());
    bounds_rect.setOrigin(GetOrigin());
    bounds_rect.setFillColor(sf::Color(0));
    bounds_rect.setOutlineThickness(-1.f);
    bounds_rect.setOutlineColor(sf::Color::Red);

    // Draw bounds rect
    event.Window.draw(bounds_rect);
}
