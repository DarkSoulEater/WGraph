#include "AExplosion.h"

AExplosion::AExplosion() : AFire({0, 0}) {
    sprite_.setScale(1, 1);

    sprite_.setOrigin(rect_size_.x / 2, rect_size_.y / 1.5);

    SetSpeed(0.1f);
    SetLooping(false);
}

bool AExplosion::UpdateFrame()
{
    const static sf::Vector2i positions[] = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0},
        {7, 0},
        {0, 1},
        {1, 1},
        {2, 1},
        {3, 1},
        {4, 1},
        {5, 1},
        {6, 1},
        {7, 1},
        {0, 2},
        {1, 2},
    };

    if (index_ >= sizeof(positions) / sizeof(sf::Vector2i)) {
        return false;
    }

    rect_pos_ =  positions[index_++];
    return true;
}