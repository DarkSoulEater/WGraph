#include "ABlueFire.h"

ABlueFire::ABlueFire(const Vector2& pivot) : AFire(pivot) {}

bool ABlueFire::UpdateFrame() {
    const static sf::Vector2i positions[] = {
        {1, 6},
        {0, 6},
        {7, 5},
        {6, 5},
        {5, 5},
        {4, 5},
        {3, 5},
        {2, 5},
        {1, 5},
        {0, 5},
        {7, 4},
        {6, 4},
    };

    rect_pos_ =  positions[index_++ % (sizeof(positions) / sizeof(sf::Vector2i))];
    return true;
}
