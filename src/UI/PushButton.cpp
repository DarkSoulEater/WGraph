#include "PushButton.h"

PushButton::PushButton() {
    
}

PushButton::PushButton(Vector2 size, Vector2 position) {
    SetBoundsSize(size, false);
    SetPosition(position);

    image_.create(size.X, size.Y, sf::Color(79, 79, 79));
    texture_.loadFromImage(image_);
    sprite_.setTexture(texture_);
}

void PushButton::OnClick() {
    if (action_) action_->operator()();
}

void PushButton::SetAction(Action *action) {
    action_.reset(action);
}

void PushButton::OnMouseEvent(const MouseEvent &event) {
    if (!GetGlobalBounds().Contains(event.MousePosition)) return;
    
    if (event.MouseButton[MouseButtom::kLeft].Pressed) OnClick();
}

void PushButton::OnDrawEvent(const DrawEvent &event) {
    sprite_.setPosition(MapToGlobal());
    event.Window.draw(sprite_);
}
