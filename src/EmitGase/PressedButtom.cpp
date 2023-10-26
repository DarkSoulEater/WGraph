#include "PressedButtom.h"
#include <iostream>

PressedButtom::PressedButtom(Action* action) : action_(action) {
    SetBoundsSize(Vector2(30.f));
}

void PressedButtom::OnMouseEvent(const MouseEvent &event) {
    if (!event.MouseButton[MouseButtom::kLeft].Pressed) return;

    if (!GetGlobalBounds().Contains(event.MousePosition)) return;

    OnClick();
}

void PressedButtom::OnDrawEvent(const DrawEvent &event) {
    if (animation_) {
        animation_->Update(event);
        sf::Sprite& anim_sprite = animation_->GetSprite();
        anim_sprite.setPosition(MapToGlobal());
        event.Window.draw(anim_sprite);
    }

    // Widget::OnDrawEvent(event);
}

void PressedButtom::SetAnimation(Animation *anim) {
    animation_.reset(anim);
}
