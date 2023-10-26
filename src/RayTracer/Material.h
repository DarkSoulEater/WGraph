#ifndef ___MATERIAL_H___
#define ___MATERIAL_H___

#include <SFML/Graphics.hpp>
#include "Color.h"

struct Material {
    Material() {}
    Material(const Color& color) : mColor(color) {}
    Material(const Color& color, const Color& ambient, const Color& diffuse, const Color& specular, float shininess, float reflect = 0.f) :
            mColor(color), mAmbient(ambient), mDiffuse(diffuse), mSpecular(specular), mShininess(shininess), mReflect(reflect) {}

    Color mColor;
    Color mAmbient;
    Color mDiffuse;
    Color mSpecular;
    float mShininess = 1.f;
    float mReflect;

    static Material GetIvory()  { return {{0.4, 0.4, 0.3}, Color(0.1f), Color(0.9), Color(0.5), 50.f, 0.1f}; }
    static Material GetGlass()  { return {{0.6, 0.7, 0.8}, Color(0.1f), Color(0.0), Color(0.9), 125.f, 0.6f}; }
    static Material GetMirror() { return {{1.f, 1.f, 1.f}, Color(0.1f), Color(0.0), Color(16.), 1425.f, 0.8f}; }
    static Material GetRubber(const Color& color = Color(0.3, 0.1, 0.1)) { return {color, Color(0.1f), Color(1.4), Color(0.3), 10.f, 0.0f}; }
};

#endif // ___MATERIAL_H___