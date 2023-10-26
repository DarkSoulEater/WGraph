#include "Animation.h"
#include <iostream>

static sf::Vector2i operator*(const sf::Vector2i& lhs, const sf::Vector2i& rhs) {
    return {lhs.x * rhs.x, lhs.y * rhs.y};
}

Animation::Animation(const std::string_view &path) {
    image_.loadFromFile(path.data());
    texture_.loadFromImage(image_);
    sprite_.setTexture(texture_);

    texture_size_ = texture_.getSize();
    sprite_.setTextureRect(sf::IntRect(rect_pos_ * rect_size_, rect_size_));
}

bool Animation::Update(const DrawEvent &event) {
    bool res = true;

    timer_ += event.DrawDeltaTime;
    if (timer_ >= speed_) {
        timer_ = 0;
        res = UpdateFrame();
    }

    sprite_.setTextureRect(sf::IntRect(rect_pos_ * rect_size_, rect_size_));
    return res;
}