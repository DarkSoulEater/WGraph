#ifndef ___VEC_H___
#define ___VEC_H___

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Math/Vector2i.h"

class Vector2 {
public:
    Vector2(float x, float y) : X(x), Y(y) {}
    Vector2(const Vector2& other) : X(other.X), Y(other.Y) {}
    Vector2(const Vector2i& other) : X(other.x), Y(other.y) {}
    Vector2(const sf::Vector2f& other) : X(other.x), Y(other.y) {}
    explicit Vector2(float val) : X(val), Y(val) {}

    ~Vector2() = default; // TODO: Add posion

    friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
    friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

    Vector2 operator-() const;

    friend Vector2 operator*(const Vector2& vec, float scale);
    friend Vector2 operator*(float scale, const Vector2& vec);
    friend Vector2 operator/(const Vector2& vec, float scale);

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float scale);
    Vector2& operator/=(float scale);

    operator sf::Vector2f() const {return sf::Vector2f(X, Y);}
    operator sf::Vector2i() const {return sf::Vector2i(X, Y);}

    //std::ostream& operator<<(std::ostream& out) const;

    void Dump() const;

    float Len() const;
    float Dot(const Vector2& other) const;

    Vector2 Normal() const;

    void Rotate(float angle);
    void Normalize();

    static Vector2 Normalize(const Vector2& vec);
    static Vector2 Reflect(const Vector2& vec, const Vector2& normal);

public:
    float X, Y;
};

Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

#endif // ___VEC_H___