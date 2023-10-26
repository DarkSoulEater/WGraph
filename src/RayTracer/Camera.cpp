#include "Camera.h"
#include <cmath>
#include <iostream> // TODO: del
#include <limits>
#include "Sphere.h"
#include <chrono> // TODO: del
#include <omp.h>
#include "DirectionalLight.h"
#include "Model3D.h"


float Radians(float angle) {
    const float PI = 3.14159265359;
    return PI / 180.f * angle;
}

void Camera::Run() {
    return;
    transform_.Move({0, 0, -18});

    auto time{std::chrono::steady_clock::now()};

    while (true) {
        auto end{std::chrono::steady_clock::now()};
        float delta_time = std::chrono::duration<float>(end - time).count();
        time = end;
        //std::cout << delta_time << "\n";
        std::cout << "FPS: " << 1 / delta_time << "\n";

        sf::Event event;
        while (false) {
            switch (event.type) {
                case sf::Event::Closed: {
                    //window_.close();
                } break;
                
                case sf::Event::KeyPressed: {
                    switch (event.key.code) {
                        case sf::Keyboard::W: {
                            transform_.Move(Vector3::Up() * delta_time);
                        } break;

                        case sf::Keyboard::S: {
                            transform_.Move(Vector3::Down() * delta_time);
                        } break;

                        case sf::Keyboard::A: {
                            transform_.Move(Vector3::Left() * delta_time);
                        } break;

                        case sf::Keyboard::D: {
                            transform_.Move(Vector3::Right() * delta_time);
                        } break;

                        case sf::Keyboard::Escape: {
                            //window_.close();
                        } break;

                        default: {

                        } break;
                    }
                } break;

                default: {
                } break;
            }
        }


        //window_.clear(sf::Color::White);

        //Render();

        //window_.display();
    }
}

void Camera::SwitchRotateLight() {
    rotate_light_ = !rotate_light_;
    std::cout << "Switch light: " << rotate_light_ << "\n";
}

void Camera::SwitchRotateCamera() {
    rotate_camera_ = !rotate_camera_;
    std::cout << "Switch camera: " << rotate_light_ << "\n";
}

Hit Camera::SceneIntersect(const Vector3 &orig, const Vector3 &dir) {
    Hit hit;
    for (const auto& obj : objs) {
        Hit obj_hit = obj->RayIntersect(orig, dir);
        if (!obj_hit || obj_hit.Distance > hit.Distance) continue;
        hit = obj_hit;
    }

    return hit;
}

Color Camera::Raycast(const Vector3 &orig, const Vector3 &dir, const int depth) {
    //orig.Dump();
    //dir.Dump();
    Color background_color = Color(0.4, 0.4, 0.7);

    const int kMaxDepth = 4;
    if (depth > kMaxDepth) return background_color;

    Hit hit = SceneIntersect(orig, dir);
    if (!hit) return background_color;

    Vector3 reflect_dir = Vector3::Normalize(Vector3::Reflect(-dir, hit.Normal));
    //Color reflect_color = {reflect_dir.X, reflect_dir.Y, reflect_dir.Z};
    Color reflect_color = Raycast(hit.Point, reflect_dir, depth + 1);

    Color ambient_intensity(0.7f);
    Color diffuse_intensity  = Color(0.f);
    Color specular_intensity = Color(0.f); 

    for (const auto& light: lights) {
        Vector3 light_pos = light.GetPosition();
        Vector3 light_dir = Vector3::Normalize(light_pos - hit.Point);

        /*bool is_light_blocked = false;
        for (const auto& sph : spheres) {
            Hit lghit;
            if (sphere.RayIntersect(hit.Point + light_dir * 1e-3f, light_dir, lghit)) {
                is_light_blocked = true;
            }
        }
        if (is_light_blocked) continue;
        */

        // Specular light vector
        Vector3 R = 2.f * hit.Normal * Vector3::Dot(light_dir, hit.Normal) - light_dir;
        
        // Light intensity
        const Color& diffuse_light_intensity  = light.GetDiffuseIntensity();
        const Color& specular_light_intensity = light.GetSpecularIntensity();

        diffuse_intensity  += diffuse_light_intensity * std::max(0.f, Vector3::Dot(light_dir, hit.Normal));
        specular_intensity += specular_light_intensity * std::pow(std::max(0.f, Vector3::Dot(R, -dir)), hit.pMaterial->mShininess); // TODO: Add check diffuse angle
    }

    ambient_intensity *= hit.pMaterial->mAmbient;

    diffuse_intensity *= hit.pMaterial->mColor;
    diffuse_intensity *= hit.pMaterial->mDiffuse;

    specular_intensity *= Color::One();
    specular_intensity *= hit.pMaterial->mSpecular;

    reflect_color *= hit.pMaterial->mReflect;

    //Color color  = diffuse_intensity * hit.pMaterial->mColor * hit.pMaterial->mDiffuse;
    //color += specular_intensity * Color::One() * hit.pMaterial->mSpecular;
    //color += reflect_color * hit.pMaterial->mReflect;
    return ambient_intensity + diffuse_intensity + specular_intensity + reflect_color;

    //std::cout << "OK\n";
    return hit.Normal;
    return hit.pMaterial->mColor;
    /*loat z = std::numeric_limits<float>::infinity();
    for (const auto& sphere : spheres) {
        Hit hit;
        if (!sphere.RayIntersect(orig, dir, hit)) continue;

        if (hit.Distance > z) continue;
        z = hit.Distance;

        hit_color = {hit.Point.X, hit.Point.Y, hit.Point.Z};
        hit_color = {hit.Normal.X, hit.Normal.Y, hit.Normal.Z};
        //hit_color = Color(hit.Distance);
        //hit_color = {hit.Normal.X, hit.Normal.Y, hit.Normal.Z};

        Vector3 reflect_dir = Vector3::Normalize(Vector3::Reflect(dir, hit.Normal));
        //Color reflect_color = {reflect_dir.X, reflect_dir.Y, reflect_dir.Z};
        Color reflect_color = Raycast(hit.Point + hit.Normal * 1e-3f, reflect_dir, depth + 1);

        // Ambient Light
        Color ambient_light_intensity(0.15f);

        Color diffuse_intensity  = Color(0.f);
        Color specular_intensity = Color(0.f); 

        // Diffuse Light
        for (const auto& light: lights) {
            Vector3 light_pos = light.GetPosition();
            Vector3 light_dir = Vector3::Normalize(light_pos - hit.Point);

            /*bool is_light_blocked = false;
            for (const auto& sph : spheres) {
                Hit lghit;
                if (sphere.RayIntersect(hit.Point + light_dir * 1e-3f, light_dir, lghit)) {
                    is_light_blocked = true;
                }
            }
            if (is_light_blocked) continue;
            * /

            // Specular light vector
            Vector3 R = 2.f * hit.Normal * Vector3::Dot(light_dir, hit.Normal) - light_dir;
            
            // Light intensity
            const Color& diffuse_light_intensity  = light.GetDiffuseIntensity();
            const Color& specular_light_intensity = light.GetSpecularIntensity();

            diffuse_intensity  += diffuse_light_intensity * std::max(0.f, Vector3::Dot(light_dir, hit.Normal));
            specular_intensity += specular_light_intensity * std::pow(std::max(0.f, Vector3::Dot(R, -dir)), hit.pMaterial->mShininess); // TODO: Add check diffuse angle
        }

        //std::cout << diffuse_intensity.r << "\n";

        color  = diffuse_intensity * hit.pMaterial->mColor * hit.pMaterial->mDiffuse;
        color += specular_intensity * Color::One() * hit.pMaterial->mSpecular;
        color += reflect_color * hit.pMaterial->mReflect;
    }*/
}

void Camera::Render(sf::RenderWindow& window) {
    const int width_ = window.getSize().x;
    const int height_ = window.getSize().y;

    sf::Image frame_buffer;
    frame_buffer.create(width_, height_, sf::Color::Blue);

    float wscale = (2 * std::tan(Radians(fov_ / 2) * dist_)) / width_;
    float hscale = (2 * std::tan(Radians(fov_ / 2) * dist_)) / height_;

    //std::cout << wscale << " " << hscale << "\n\n";

    Vector3 position = transform_.GetPosition();

    #pragma omp parallel for
    for (uint32_t j = 0; j < height_; ++j) {
        #pragma omp parallel for
        for (uint32_t i = 0; i < width_; ++i) {
            float x = ((int)i - (int)width_ / 2) * wscale;
            float y = ((int)height_ / 2 - (int)j) * hscale;
            Vector3 dir = Vector3::Normalize(transform_.ToGlobalCoords(Vector3(x, y, 1)) - transform_.GetPosition());

            x = i - width_ / 2.f;
            y = height_ / 2.f - j;
            float z = (int)height_ / (2.f * tan(1.05 / 2.f));
            //std::cout << z << "\n";
            dir = Vector3::Normalize(transform_.ToGlobalCoords(Vector3(x, y, z)) - transform_.GetPosition());

            Color color = Raycast(position, dir, 0);
            float mx = std::max(1.f, std::max(color.X, std::max(color.Y, color.Z)));
            color /= mx; // TODO:
            sf::Color cl = sf::Color(255 * color.X, 255 * color.Y,  255 * color.Z); // TODO
            frame_buffer.setPixel(i, j, cl);

            //printf("(%f,%f) ", x, y);
        }
        //printf("\n");
    }

    //Vector3 v = transform_.Forward();
    //v.Dump();
    //exit(0);

    sf::Texture texture;
    texture.create(width_, height_);
    texture.update(frame_buffer);
    sf::Sprite sprite(texture);
    window.draw(sprite);
}

void Camera::Update() {
    static auto time{std::chrono::steady_clock::now()};
    auto end{std::chrono::steady_clock::now()};
    float delta_time = std::chrono::duration<float>(end - time).count();
    time = end;
    //std::cout << delta_time << "\n";
    std::cout << "FPS: " << 1 / delta_time << "\n";

    if (rotate_light_) {
        auto& light = lights[0];
        Vector3 pivot = Vector3(0, 0, 0);
        Vector3 dir = light.GetPosition() - pivot;
        //dir.Dump();
        dir = Vector3::Rotate(dir, Radians(60 * delta_time), AxisY);
        //dir.Dump();
        light.transform_.Move(pivot + dir - light.GetPosition());
    }

    if (rotate_camera_) {
        float angle = Radians(40 * delta_time);
        Vector3 pivot = Vector3(0, 0, 0);
        Vector3 dir = transform_.GetPosition() - pivot;
        //dir.Dump();
        dir = Vector3::Rotate(dir, angle, AxisY);
        transform_.Rotate(angle, AxisY);
        //transform_.Forward().Dump();
        //(transform_.GetPosition() + transform_.Forward() * 10.f).Dump();
        //dir.Dump();
        transform_.Move(pivot + dir - transform_.GetPosition());
        //transform_.GetPosition().Dump();
    }
}

void Camera::Draw(sf::RenderWindow &window) {
    Render(window);
}
