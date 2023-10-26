#ifndef ___PISTON_H___
#define ___PISTON_H___

#include "UI/Widget.h"
#include "SFML/Graphics.hpp"

class Piston : public Widget {
public:
    Piston(Vector2 box_size) : box_size_(box_size) { SetBoundsSize(Vector2(box_size.X, thickness_), false); }

    virtual void OnMouseEvent(const MouseEvent& event);
    virtual void OnDrawEvent(const DrawEvent& event);

    float GetThickness() const { return thickness_; }

private:
    Vector2 box_size_;
    float thickness_ = 40.f;
};

#endif // ___PISTON_H___