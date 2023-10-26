#ifndef ___CAMERA_H___
#define ___CAMERA_H___

#include "SFML/Graphics.hpp"
#include "Transform.h"
#include "Vector3.h"
#include "Core/Object.h"
#include "RayTracer/RenderingObject.h"
#include "DirectionalLight.h"
#include "Sphere.h"

class Camera : public Object {
public:
    //Camera() :  width_(1000), height_(1000), window_(sf::VideoMode(width_, height_), "Camera") {}
    Camera() {transform_.Move({0, 0, -18});} // TODO:
    ~Camera() = default;

    void Run(); // TODO: TMP
    void SwitchRotateCamera();
    void SwitchRotateLight();

private:
    Transform transform_;    

    float dist_ = 1.f;
    float fov_ = 90.f;

    bool rotate_light_  = false;
    bool rotate_camera_ = false;

private:
    Hit SceneIntersect(const Vector3& orig, const Vector3& dir);
    Color Raycast(const Vector3& orig, const Vector3& dir, const int depth);

    void Render(sf::RenderWindow& window);

    virtual void Update() override;
    virtual void Draw(sf::RenderWindow& window) override;

private: // TODO: TMP
    //const uint32_t width_;
    //const uint32_t height_;
    //sf::RenderWindow window_;


    DirectionalLight lights[3] = {
        DirectionalLight(Transform(Vector3(-20, 20, 38)), Color(1.f)),
        DirectionalLight(Transform(Vector3(30, 50,  -13)), Color(1.f)),
        DirectionalLight(Transform(Vector3(30, 20, 48)), Color(1.f)),
    };

    RenderingObject* objs[4] = {
        new Sphere(Transform(Vector3(-3, 0, -2)), 2.f,    Material::GetIvory()),
        new Sphere(Transform(Vector3(-1, -1.5, -6)), 2.f,    Material::GetGlass()),
        new Sphere(Transform(Vector3(1.5,-0.5, 0)), 3.f, Material::GetRubber()),
        new Sphere(Transform(Vector3(7, 5, -4)), 4.f,  Material::GetMirror())
    };
};

#endif // ___CAMERA_H___