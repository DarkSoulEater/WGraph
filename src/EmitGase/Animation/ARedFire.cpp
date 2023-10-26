#include "ARedFire.h"

ARedFire::ARedFire(const Vector2 &pivot) : AFire(pivot) {}

bool ARedFire::UpdateFrame() {
    const static sf::Vector2i positions[] = {
        {5, 7},
        {4, 7},
        {3, 7},
        {2, 7},
        {1, 7},
        {0, 7},
        {7, 6},
        {6, 6},
        {5, 6},
        {4, 6},
        {3, 6},
        {2, 6}
    };

    rect_pos_ =  positions[index_++ % (sizeof(positions) / sizeof(sf::Vector2i))];
    return true;
}
