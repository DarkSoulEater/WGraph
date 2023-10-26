#ifndef ___DIRECTIONALLIGHT_H___
#define ___DIRECTIONALLIGHT_H___

#include <Transform.h>
#include "Color.h"

class DirectionalLight {
public:
    DirectionalLight() {}
    explicit DirectionalLight(const Transform& transform, 
                              const Color& diffuse_intensity = Color::One(), 
                              const Color& specular_intensity = Color::One()) 
                                :   transform_(transform), 
                                    diffuse_intensity_(diffuse_intensity),
                                    specular_intensity_(specular_intensity) {}
    ~DirectionalLight() = default;

    Vector3 GetPosition() const { return transform_.GetPosition(); }

    //float GetIntensity() const { return intensity_; }
    const Color& GetDiffuseIntensity()  const { return diffuse_intensity_; }
    const Color& GetSpecularIntensity() const { return specular_intensity_; }

public: // TODO: to private
    Transform transform_;
private:
    Color diffuse_intensity_;
    Color specular_intensity_;
};

#endif // ___DIRECTIONALLIGHT_H___