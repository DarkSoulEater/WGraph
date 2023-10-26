#include <assert.h>
#include "Math/FloatRect.h"
#include <iostream>
#include "FloatRect.h"

bool FloatRect::Contains(float x, float y) {
    if (x < position_.X || x > position_.X + size_.X) return false;
    if (y < position_.Y || y > position_.Y + size_.Y) return false;
    return true;
}

bool FloatRect::Contains(const Vector2 &point) {
    return Contains(point.X, point.Y);
}

void FloatRect::Dump() {
    printf("FloatRect:[\n"
           "\t(%f, %f) --- (%f, %f)\n"
           "\t|                   |\n"
           "\t(%f, %f) --- (%f, %f)\n"
           "]\n", 
           position_.X,           position_.Y,
           position_.X + size_.X, position_.Y,
           position_.X,           position_.Y + size_.Y,
           position_.X + size_.X, position_.Y + position_.Y);
}

bool FloatRect::Intersects(const FloatRect &rect) {
    sf::FloatRect first(position_, size_);
    sf::FloatRect second(Vector2(rect.position_), Vector2(rect.size_));
    return first.intersects(second); // TODO:
}
