#ifndef ___SPHERE_H___
#define ___SPHERE_H___

#include "Vector3.h"
#include "RayTracer/RenderingObject.h"
#include "Transform.h"
#include "Material.h"
#include "Hit.h"

class Sphere : public RenderingObject {
public:
    Sphere(const Transform& transform, float radius, const Material& material = Material()) : transform_(transform), radius_(radius), material_(material) {}
    virtual ~Sphere() override {};

    float GetRadius() const { return radius_; }
    Vector3 GetPosition() const { return transform_.GetPosition(); }

    virtual Hit RayIntersect(const Vector3& origin, const Vector3& direction) const override;

private:
    Transform transform_;
    float radius_;

    Material material_;
};

#endif // ___SPHERE_H___