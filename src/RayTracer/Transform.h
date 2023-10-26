#ifndef ___TRANSFORM_H___
#define ___TRANSFORM_H___

#include "Math/Vector3.h"
#include "Math/Matrix3x3.h"

class Transform {
public:
    Transform() {}
    explicit Transform(const Vector3& position) : centre_(position) {}
    ~Transform() = default;

    void Move(const Vector3& vec);
    void Rotate(float angle, Axis axis);

    Vector3 ToLocalCoords(const Vector3& global) const;
    Vector3 ToGlobalCoords(const Vector3& local) const;

    Vector3 GetPosition() const { return centre_; }

    Vector3 Forward() const { return GlobalCoordsMatrix() * Vector3::Forward(); }

protected:
    inline Matrix3x3 LocalCoordsMatrix() const;
    inline Matrix3x3 GlobalCoordsMatrix() const;

public: // TODO:
    Vector3 centre_ = Vector3::Zero();
    Vector3 axisX_  = Vector3::Right();
    Vector3 axisY_  = Vector3::Up();
    Vector3 axisZ_  = Vector3::Forward();
};

#include "Transform.hpp"

#endif // ___TRANSFORM_H___