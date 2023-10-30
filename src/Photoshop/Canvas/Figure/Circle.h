#ifndef ___CIRCLE_H___
#define ___CIRCLE_H___

#include "Photoshop/Canvas/Figure/Figure.h"
#include "Math/Vector2.h"
#include "Photoshop/Tool/Color.h"

class Circle : public Figure {
public:
    Circle(Vector2 centre, float radius = 0) : centre_(centre), radius_(radius) {}

    virtual void Draw(sf::RenderTarget& rt) override;

    float GetRadius()             { return radius_; }
    void  SetRadius(float radius) { radius_ = radius; }

    Vector2 GetCentre()               { return centre_; }
    void    SetCentre(Vector2 centre) { centre_ = centre; }

    void SetFillColor(Color color)    { fill_color_ = color; }
    void SetOutlineColor(Color color) { outline_color_ = color; }

private:
    Vector2 centre_;
    float radius_;

    Color fill_color_    = Color::Black;
    Color outline_color_ = Color::White;
};

#endif // ___CIRCLE_H___