#include "Transform.h"

void Transform::Move(const Vector3 &vec) {
    centre_ += vec;
}

void Transform::Rotate(float angle, Axis axis) {
    axisX_ = Vector3::Rotate(axisX_, angle, axis);
    axisY_ = Vector3::Rotate(axisY_, angle, axis);
    axisZ_ = Vector3::Rotate(axisZ_, angle, axis);
}

Vector3 Transform::ToLocalCoords(const Vector3 &global) const {
    return LocalCoordsMatrix() * (global - centre_);
}

Vector3 Transform::ToGlobalCoords(const Vector3 &local) const {
    return (GlobalCoordsMatrix() * local) + centre_;
}
