#include "Vector3.h"
#include <assert.h>
#include <cmath>
#include <iostream>
#include "Matrix3x3.h"

Vector3 operator+(const Vector3& lhs, const Vector3& rhs) {
    Vector3 vec = lhs;
    vec += rhs;
    return vec;
}

Vector3 operator-(const Vector3& lhs, const Vector3& rhs) {
    Vector3 vec = lhs;
    vec -= rhs;
    return vec;
}

Vector3 operator*(const Vector3 &vec, float factor) {
    Vector3 res = vec;
    res *= factor;
    return res;
}

Vector3 operator*(float factor, const Vector3 &vec) {
    return vec * factor;
}

Vector3 Vector3::operator-() const {
    Vector3 res = Vector3::Zero();
    res -= *this;
    return res;
}

Vector3 &Vector3::operator+=(const Vector3 &other) {
    X += other.X, Y += other.Y, Z += other.Z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3 &other) {
    X -= other.X, Y -= other.Y, Z -= other.Z;
    return *this;
}

Vector3 &Vector3::operator*=(const Vector3 &other) {
    X *= other.X, Y *= other.Y, Z *= other.Z;
    return *this;
}

Vector3 &Vector3::operator*=(float factor) {
    X *= factor, Y *= factor, Z *= factor;
    return *this;
}

Vector3& Vector3::operator/=(float factor) {
    X /= factor, Y /= factor, Z /= factor;
    return *this;
}

float Vector3::Dot(const Vector3 &lhs, const Vector3 &rhs) {
    return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
}

float Vector3::Lenght(const Vector3 &vec) {
    return std::sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z);
}

Vector3 Vector3::Normalize(const Vector3 &vec) {
    Vector3 res = vec;
    res /= Lenght(vec);
    return res;
}

Vector3 Vector3::Reflect(const Vector3 &vec, const Vector3 &normal) {
    return vec - 2.f * normal * Vector3::Dot(vec, normal);
}

Vector3 Vector3::Rotate(const Vector3 &vec, float angle, Axis axis) {
    switch (axis) {
        case Axis::AxisX: {
            return Vector3::RotateYZ(vec, angle);
        } break;

        case Axis::AxisY: {
            return Vector3::RotateXZ(vec, angle);
        }

        case Axis::AxisZ: {
            return Vector3::RotateXY(vec, angle);
        }

        default: assert(0);
    }
}

Vector3 Vector3::RotateXY(const Vector3 &vec, float angle) {
    Matrix3x3 rot_matr = {
        std::cos(angle), -std::sin(angle), 0,
        std::sin(angle),  std::cos(angle), 0,
        0, 0, 1
    };
    return rot_matr * vec;
}

Vector3 Vector3::RotateXZ(const Vector3 &vec, float angle) {
    Matrix3x3 rot_matr = {
        std::cos(angle), 0, -std::sin(angle),
        0, 1, 0,
        std::sin(angle), 0,  std::cos(angle),
    };
    return rot_matr * vec;
}

Vector3 Vector3::RotateYZ(const Vector3 &vec, float angle) {
    Matrix3x3 rot_matr = {
        1, 0, 0,
        0, std::cos(angle), -std::sin(angle),
        0, std::sin(angle),  std::cos(angle),
    };
    return rot_matr * vec;
}

void Vector3::Dump() const
{
    printf("(%f, %f, %f)\n", X, Y, Z);
}
