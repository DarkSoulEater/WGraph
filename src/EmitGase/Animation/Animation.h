#ifndef ___ANIMATION_H___
#define ___ANIMATION_H___

#include "SFML/Graphics.hpp"
#include "Core/Event/DrawEvent.h"

class Animation {
public:
    //Animation() {}
    Animation(const std::string_view& path);
    virtual ~Animation() {};

    bool Update(const DrawEvent& event);

protected:
    virtual bool UpdateFrame() = 0;

public:
    void SetSpeed(float speed) { speed_ = speed; }
    void SetLooping(bool is_looping) { is_looping_ = is_looping; }

    sf::Sprite& GetSprite() { return sprite_; } 

protected:
    float timer_ = 0.f;
    float speed_ = 1.f;
    bool is_looping_ = false;

protected:
    sf::Image image_;
    sf::Texture texture_;
    sf::Sprite sprite_;

    sf::Vector2u texture_size_;
    sf::Vector2i rect_size_ = {0, 0};
    sf::Vector2i rect_pos_  = {0, 0};
};

#endif // ___ANIMATION_H___