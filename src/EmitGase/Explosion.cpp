#include "Explosion.h"
#include <assert.h>
#include "EmitGase/Animation/AExplosion.h"


static sf::Vector2i operator*(const sf::Vector2i& lhs, const sf::Vector2i& rhs) {
    return {lhs.x * rhs.x, lhs.y * rhs.y};
}

Explosion::Explosion() : animation_(new AExplosion()) {}

void Explosion::OnDrawEvent(const DrawEvent &event) {
    assert(animation_);

    if (!animation_->Update(event)) {
        SetEnabled(false);
        return;
    }

    sf::Sprite& anim_sprite = animation_->GetSprite();
    anim_sprite.setPosition(MapToGlobal());
    event.Window.draw(anim_sprite);
}
