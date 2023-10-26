#include "Panel.h"

Panel::Panel() {
    texture_.loadFromFile("assets/forge1.jpg");
    sprite_.setTexture(texture_);
}

void Panel::OnDrawEvent(const DrawEvent &event) {
    event.Window.draw(sprite_);
}
