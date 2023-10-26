#include "AFire.h"

AFire::AFire(const Vector2 &pivot) : Animation("assets/fire.jpg") {
    image_.createMaskFromColor(image_.getPixel(0, 0));
    texture_.loadFromImage(image_);

    sprite_.setScale(0.55, 0.55);
    sprite_.setOrigin(pivot.X * 4, pivot.Y * 6.5);

    rect_size_ = {texture_size_.x / 8, texture_size_.y / 8};

    SetSpeed(0.07f);
    SetLooping(true);
}