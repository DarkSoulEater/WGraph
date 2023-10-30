#include "PushButton.h"

PushButton::PushButton() { }

PushButton::PushButton(Vector2 size, Vector2 position) {
    SetBoundsSize(size, false);
    SetPosition(position);

    image_.create(size.X, size.Y, sf::Color(79, 79, 79));
    backtexture_.loadFromImage(image_);
    backsprite_.setTexture(backtexture_);
}

void PushButton::SetSize(Vector2 size) {
    SetBoundsSize(size, false);

    image_.create(size.X, size.Y, sf::Color(79, 79, 79));
    backtexture_.loadFromImage(image_);
    backsprite_.setTexture(backtexture_);   
}

void PushButton::SetColor(Color color) {
    Vector2 size = sf::Vector2f(image_.getSize());
    image_.create(size.X, size.Y, color);
    backtexture_.loadFromImage(image_);
    backsprite_.setTexture(backtexture_);   
}

void PushButton::UpdateTexture(const char *path) {
    fronttexture_.loadFromFile(path);
    frontsprite_.setTexture(fronttexture_);
    frontsprite_.setScale((float)image_.getSize().x / (float)fronttexture_.getSize().x,
                          (float)image_.getSize().y / (float)fronttexture_.getSize().y);
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
    backsprite_.setPosition(MapToGlobal());
    event.Window.draw(backsprite_);

    frontsprite_.setPosition(MapToGlobal());
    event.Window.draw(frontsprite_);

    // Widget::OnDrawEvent(event);
}
