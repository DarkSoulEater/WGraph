#ifndef ___MODEL3D_H___
#define ___MODEL3D_H___

#include <string_view>
#include <vector>
#include "Math/Vector3.h"

class Model3D {
public:
    Model3D() {}
    ~Model3D() = default;

    void Load(const std::string_view& file_name);

    float RayIntersect(const Vector3 &orig, const Vector3 &dir);

private:
    std::vector<Vector3> vertices;
    std::vector<int> indexes;
};

#endif // ___MODEL3D_H___