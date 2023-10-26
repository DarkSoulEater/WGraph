#ifndef ___COLOR_H___
#define ___COLOR_H___

#include <assert.h>
#include <iostream>
#include <Vector3.h>
#include <SFML/Graphics.hpp>

typedef Vector3 Color;

/*struct Color {
    Color() {}
    Color(float R, float G, float B, float A = 1.f) : r(R), g(G), b(B), a(A) {}
    explicit Color(float val, float A = 1.f) : r(val), g(val), b(val), a(A) {}
    Color(const sf::Color& color) : r(color.r / 255.f), g(color.g / 255.f), b(color.b / 255.f), a(color.a / 255.f) {}
    ~Color() = default;

    friend Color operator*(const Color& lhs, const Color& rhs) { return Color(lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b, lhs.a * rhs.a); }
    friend Color operator*(const Color& color, float factor) { return Color(color.r * factor, color.g * factor, color.b * factor, color.a * factor); }
    friend Color operator*(float factor, const Color& color) { return Color(color.r * factor, color.g * factor, color.b * factor, color.a * factor); }
    friend Color operator/(const Color& color, float factor) { return Color(color.r / factor, color.g / factor, color.b / factor); }

    Color& operator+=(const Color& other);
    //Color& operator/=(const Color& other);

    void Dump() { printf("[.r = %f, .g = %f, .b = %f, .a = %a]", r, g, b, a); }

    explicit operator sf::Color() { return sf::Color(r * 255, g * 255, b * 255, 255); } // TODO: ADD a

public:
    float r = 1.f, g = 1.f, b = 1.f, a = 1.f;

    static Color Zero() { return Color(0.f, 0.f, 0.f); }
    static Color One()  { return Color(1.f, 1.f, 1.f, 1.f); }

};*/

#endif // ___COLOR_H___