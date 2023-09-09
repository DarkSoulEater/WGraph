#include "Camera.h"
#include <cmath>

Camera::Camera() : width_(1000), height_(1000), window_(sf::VideoMode(width_, height_), "Camera") {

}

void Camera::Run() {
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // TODO: add switch
                window_.close();
            }
        }

        window_.clear(sf::Color::White);

        // 

        window_.display();
    }
}

float Radians(float angle) {
    const float PI = 3.14159265359;
    return PI / 180.f * angle;
}

void Camera::Render() {
    for (uint32_t j = 0; j < height_; ++j) {
        for (uint32_t i = 0; i < width_; ++i) {
            float x = pos_.X + std::tan(fov_ / 2) * ;
        }
    }
}
