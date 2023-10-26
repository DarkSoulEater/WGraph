#include "EmitGase/Piston.h"
#include "EmitGase/Event/CapMoveEvent.h"

void Piston::OnMouseEvent(const MouseEvent &event) {
    static bool mouse_button_pressed = false;
    if (event.MouseButton[MouseButtom::kLeft].Pressed)  {
        if (GetGlobalBounds().Contains(event.MousePosition.x, event.MousePosition.y)) {
            mouse_button_pressed = true;
        }
    }
    if (event.MouseButton[MouseButtom::kLeft].Released) mouse_button_pressed = false;

    if (mouse_button_pressed) {
        Vector2 delta = position_ - MapFromGlobal(event.MouseOldPosition);
        Vector2 mouse_position = MapFromGlobal(event.MousePosition);
        Vector2 mouse_parent_pos = MapToParent(mouse_position);
        if (mouse_parent_pos.Y >= 0 && mouse_parent_pos.Y <= box_size_.Y) { // TODO: movement within the boundaries of boxing
            position_ = Vector2(position_.X, mouse_position.Y + delta.Y);

            Object* parent = GetParent();
            if (parent) {
                CapMoveEvent event;
                event.NewUpperButtom = position_.Y + thickness_;
                parent->OnEvent(&event);
            }
        }
    }

    if (position_.Y < 0) position_.Y = 0;
    if (position_.Y > box_size_.Y - thickness_) position_.Y = box_size_.Y - thickness_;
}

void Piston::OnDrawEvent(const DrawEvent &event) {
    //position_ = {0, 0};
    sf::RectangleShape cap({box_size_.X, thickness_});
    cap.setPosition(MapToGlobal());
    cap.setFillColor(sf::Color(0, 0, 0, 170));
    event.Window.draw(cap);

    // auto bounds_rect = GetGlobalBounds();
    // sf::RectangleShape bounds(bounds_rect.GetSize());
    // bounds.setFillColor(sf::Color(0, 0, 0, 0));
    // bounds.setPosition(bounds_rect.GetPosition());
    // bounds.setOutlineColor(sf::Color::Red);
    // bounds.setOutlineThickness(1);
    // event.Window.draw(bounds);;
}
