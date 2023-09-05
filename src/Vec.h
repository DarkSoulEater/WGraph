#ifndef ___VEC_H___
#define ___VEC_H___

#include <iostream>

template<typename T>
class Vector2 {
public:
    Vector2(double x, double y) : x_(x), y_(y) {}
    explicit Vector2(double val) : x_(val), y_(val) {}

    ~Vector2() = default;

    friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
    friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

    Vector2 operator-();

    friend Vector2 operator*(const Vector2& vec, double scale);
    friend Vector2 operator*(double scale, const Vector2& vec);
    friend Vector2 operator/(const Vector2& vec, double scale);

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(double scale);
    Vector2& operator/=(double scale);

    std::ostream& operator<<(std::ostream& out) const;

    void dump() const;

    double len() const;

    void rotate(double angle);
    void norm();

private:
    double x_, y_;
};

#endif // ___VEC_H___