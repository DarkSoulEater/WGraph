#ifndef ___VECTOR3_H___
#define ___VECTOR3_H___

class Vector3 {
public:
    Vector3() : X(0.f), Y(0.f), Z(0.f) {}
    Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
    ~Vector3() = default;

public:
    float X, Y, Z;
};

#endif // ___VECTOR3_H___