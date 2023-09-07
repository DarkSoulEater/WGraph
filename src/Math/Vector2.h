#ifndef ___VEC_H___
#define ___VEC_H___

#include <iostream>

class Vector2 {
public:
    Vector2(float x, float y) : X(x), Y(y) {}
    explicit Vector2(float val) : X(val), Y(val) {}

    ~Vector2() = default; // TODO: Add posion

    friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
    friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

    Vector2 operator-();

    friend Vector2 operator*(const Vector2& vec, float scale);
    friend Vector2 operator*(float scale, const Vector2& vec);
    friend Vector2 operator/(const Vector2& vec, float scale);

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float scale);
    Vector2& operator/=(float scale);

    //std::ostream& operator<<(std::ostream& out) const;

    void Dump() const;

    float Len() const;

    //void rotate(float angle);
    //void norm();

public:
    float X, Y;
};

#endif // ___VEC_H___