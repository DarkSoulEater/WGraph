#include "Math/Vector2.h"
#include <cmath>
#include "Vector2.h"

Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2(lhs.X + rhs.X, lhs.Y + rhs.Y);
}

Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2(lhs.X - rhs.X, lhs.Y - rhs.Y);
}

Vector2 Vector2::operator-() const {
    return Vector2(-X, -Y);
}

Vector2 &Vector2::operator+=(const Vector2 &other) {
    X += other.X, Y += other.Y;
    return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &other) {
    X -= other.X, Y -= other.Y;
    return *this;
}

Vector2 &Vector2::operator*=(float scale) {
    X *= scale, Y *= scale;
    return *this;
}

Vector2 &Vector2::operator/=(float scale) {
    X /= scale, Y /= scale;
    return *this;
}

void Vector2::Dump() const {
    printf("Vector2(%f, %f)\n", X, Y);
}

float Vector2::Len() const {
    return std::sqrt(X * X + Y * Y);
}

float Vector2::Dot(const Vector2 &other) const {
    return X * other.X + Y * other.Y;
}

Vector2 Vector2::Normal() const {
    Vector2 vec(Y, -X);
    vec.Normalize();
    return vec;
}

Vector2 operator*(const Vector2 &vec, float scale) {
    return Vector2(vec.X * scale, vec.Y * scale);
}

Vector2 operator*(float scale, const Vector2 &vec) {
    return Vector2(vec.X * scale, vec.Y * scale);
}

Vector2 operator/(const Vector2 &vec, float scale) {
    return Vector2(vec.X / scale, vec.Y / scale);
}

void Vector2::Rotate(float angle) {
    const float pi = 3.14159265359f;
    float newX = X * std::cos(angle * pi / 180) - Y * std::sin(angle * pi / 180);
    float newY = Y * std::cos(angle * pi / 180) + X * std::sin(angle * pi / 180);
    X = newX, Y = newY;
}

void Vector2::Normalize() {
    operator/=(Len()); // THIS /= LEN(THIS)
}

Vector2 Vector2::Normalize(const Vector2 &vec) {
    Vector2 tmp = Vector2(vec);
    tmp.Normalize();
    return tmp;
}

Vector2 Vector2::Reflect(const Vector2 &vec, const Vector2 &normal) {
    return vec - 2.f * normal * normal.Dot(vec);
}
