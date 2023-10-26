#include "Circle.h"

void Circle::Draw(sf::RenderTarget &rt) {
    sf::CircleShape circle(radius_);
    circle.setPosition(centre_);
    circle.setOrigin(Vector2(radius_));
    circle.setFillColor(fill_color_);
    circle.setOutlineColor(outline_color_);
    circle.setOutlineThickness(1);
    rt.draw(circle);
}