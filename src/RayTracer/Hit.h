#ifndef ___HIT_H___
#define ___HIT_H___

#include <limits>
#include "Math/Vector3.h"
#include "Material.h"

struct Hit {
    Hit() {}
    ~Hit() = default;

public:
    bool IsHit = false;
    float Distance = std::numeric_limits<float>::infinity();
    Vector3 Point;
    Vector3 Normal;
    const Material* pMaterial = nullptr;

    operator bool() { return IsHit; };
};

#endif // ___HIT_H___