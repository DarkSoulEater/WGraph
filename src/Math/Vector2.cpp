#include "Math/Vector2.h"
#include <cmath>

inline Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2(lhs.X + rhs.X, lhs.Y + rhs.Y);
}

inline Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2(lhs.X - rhs.X, lhs.Y - rhs.Y);
}

inline Vector2 Vector2::operator-() {
    return Vector2(-X, -Y);
}

inline Vector2 &Vector2::operator+=(const Vector2 &other) {
    X += other.X, Y += other.Y;
    return *this;
}

inline Vector2 &Vector2::operator-=(const Vector2 &other)
{
    X -= other.X, Y -= other.Y;
    return *this;
}

inline Vector2 &Vector2::operator*=(float scale)
{
    X *= scale, Y *= scale;
    return *this;
}

inline Vector2 &Vector2::operator/=(float scale)
{
    X /= scale, Y /= scale;
    return *this;
}

void Vector2::Dump() const {
    printf("Vector2(%f, %f)\n", X, Y);
}

float Vector2::Len() const {
    return std::sqrt(X * X + Y * Y);
}

inline Vector2 operator*(const Vector2 &vec, float scale) {
    return Vector2(vec.X * scale, vec.Y * scale);
}

inline Vector2 operator*(float scale, const Vector2 &vec) {
    return Vector2(vec.X * scale, vec.Y * scale);
}

Vector2 operator/(const Vector2 &vec, float scale) {
    return Vector2(vec.X / scale, vec.Y / scale);
}

