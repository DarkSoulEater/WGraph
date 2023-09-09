#ifndef ___SPHERE_H___
#define ___SPHERE_H___

#include "Vector3.h"

class Sphere {
public:
    Sphere(const Vector3& centre, const Vector3& radius) : centre_(centre), radius_(radius) {}
    ~Sphere() = default;

private:
    Vector3 centre_;
    Vector3 radius_;
};

#endif // ___SPHERE_H___