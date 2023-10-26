#ifndef ___RENDERINGOBJECT_H___
#define ___RENDERINGOBJECT_H___

#include "RayTracer/Hit.h"

class RenderingObject {
public:
    RenderingObject() {};
    virtual ~RenderingObject() {};

    virtual Hit RayIntersect(const Vector3 &origin, const Vector3 &direction) const = 0;

private:
    /* data */
};

#endif // ___RENDERINGOBJECT_H___