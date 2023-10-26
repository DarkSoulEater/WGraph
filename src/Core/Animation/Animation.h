#ifndef ___ANIMATION_H___
#define ___ANIMATION_H___

#include "SFML/Graphics.hpp"

class Animation {
public:
    Animation();
    // ~Animation() = default;

protected:
    sf::Image image_;
    sf::Texture texture_;
    sf::Sprite sprite_;

    sf::Vector2u texture_size_;
    sf::Vector2i rect_size_ = {0, 0};
    sf::Vector2i rect_pos_  = {0, 0};
};

#endif // ___ANIMATION_H___