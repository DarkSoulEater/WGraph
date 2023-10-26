#include "SimpleAtom.h"
#include "EmitGase/Animation/ARedFire.h"

SimpleAtom::SimpleAtom(Vector2 box_position, Vector2 box_size) 
                                    : Atom(box_position, box_size), 
                                      animation_(new ARedFire(GetOrigin())) {}

void SimpleAtom::OnDrawEvent(const DrawEvent &event) {
    if (animation_) {
        animation_->Update(event);
        sf::Sprite& anim_sprite = animation_->GetSprite();
        anim_sprite.setPosition(MapToGlobal());
        event.Window.draw(anim_sprite);
    }

    //event.Window.draw(shape);

    // Atom::OnDrawEvent(event);
}
