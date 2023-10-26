#include "Sphere.h"
#include <cmath>
#include <limits>

Hit Sphere::RayIntersect(const Vector3& origin, const Vector3& direction) const {
    Hit hit;

    Vector3 centre_ = GetPosition();

    Vector3 L = centre_ - origin;
    float tca = Vector3::Dot(L, direction); // L * direction;
    float d2 = Vector3::Dot(L, L) - tca * tca; // L * L - tca*tca;
    if (d2 > radius_ * radius_) return hit;
    float thc = std::sqrt(radius_ * radius_ - d2);
    float t0 = tca-thc, t1 = tca+thc;
    if (t0>.001) {
        hit.Distance = t0;
    }  // offset the original point by .001 to avoid occlusion by the object itself
    if (t1>.001) {
        hit.Distance = t1;
    }
    //return {false, 0};

    hit.IsHit = true;
    hit.Point = origin + direction * hit.Distance;
    hit.Normal = Vector3::Normalize(hit.Point - centre_);
    hit.pMaterial = &material_;
    return hit;


    Vector3 right = centre_ - origin;
    float distance = Vector3::Lenght(right);

    float cos_angle = Vector3::Dot(Vector3::Normalize(right), direction);
    float sin_angle = std::sqrt(1 - cos_angle * cos_angle);

    //if (sin_angle * distance > radius_) return hit;

    float dist_norml = sin_angle * distance;
    // hit.Distance = distance - std::sqrt(radius_ * radius_ + dist_norml * dist_norml);

    hit.Point  = origin + direction * hit.Distance;
    hit.Normal = Vector3::Normalize(hit.Point - centre_);
    hit.pMaterial = &material_;
    hit.IsHit = true;

    return hit;
}
