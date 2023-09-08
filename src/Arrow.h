#ifndef ___ARROW_H___
#define ___ARROW_H___

#include "Shape.h"
#include "Math/Vector2.h"

class Arrow : public Shape {
public:
    Arrow(const Vector2& begin, const Vector2& end) : begin_(begin), end_(end) {};
    Arrow(Vector2 direction) : begin_(0.f), end_(direction) {};
    virtual ~Arrow() {};

    void SetColor(sf::Color color);

    void Rotate(float angle);

private:
    sf::Color color_ = sf::Color::Black;
    Vector2 begin_, end_;

protected:
    virtual void Update() override;
    virtual void Draw(sf::RenderTexture& window, const CoordsSys& coords_sys) override;
};

#endif // ___ARROW_H___