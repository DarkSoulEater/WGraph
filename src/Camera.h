#ifndef ___CAMERA_H___
#define ___CAMERA_H___

#include "SFML/Graphics.hpp"
#include "Vector3.h"

class Camera {
public:
    Camera();
    ~Camera() = default;

    void Run(); // TODO: TMP

    void Render();

private:
    Vector3 pos_;
    Vector3 dir_;
    float dist = 1;
    float fov_ = 120.f;

private: // TODO: TMP
    sf::RenderWindow window_;
    const uint32_t width_;
    const uint32_t height_;
};

#endif // ___CAMERA_H___