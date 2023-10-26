#include "DifficultAtom.h"
#include "EmitGase/Animation/ABlueFire.h"

DifficultAtom::DifficultAtom(Vector2 box_position, Vector2 box_size) : Atom(box_position, box_size), animation_(new ABlueFire(GetOrigin())) {
    SetMass(kDefMass * 2);
}

void DifficultAtom::OnDrawEvent(const DrawEvent &event) {
    if (animation_) {
        animation_->Update(event);
        sf::Sprite& anim_sprite = animation_->GetSprite();
        anim_sprite.setPosition(MapToGlobal());
        event.Window.draw(anim_sprite);
    }

    // sf::RectangleShape shape(Vector2(radius_ * 2));
    // shape.setPosition(MapToGlobal());
    // shape.setOrigin(GetOrigin());

    // shape.setFillColor(sf::Color::Blue);

    // //event.Window.draw(shape);

    // Atom::OnDrawEvent(event);
}
