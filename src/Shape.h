#ifndef ___SHAPE_H___
#define ___SHAPE_H___

#include "SFML/Graphics.hpp"
#include "CoordsSys.h"

class Shape {
public:
    friend class CoordsSys;

    Shape();
    virtual ~Shape();

protected:
    virtual void Update() = 0;
    virtual void Draw(sf::RenderTexture& window, const CoordsSys& coords_sys) = 0;

private:
    Shape* next_ = nullptr;
    Shape* prev_ = nullptr;
    static Shape* Head_; // Ptr to head of Shape list
};

#endif // ___SHAPE_H___