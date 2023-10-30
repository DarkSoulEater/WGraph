#ifndef ___FIGURE_H___
#define ___FIGURE_H___

#include "SFML/Graphics.hpp"

class Figure {
public:
    Figure() {};
    virtual ~Figure() {};

    bool IsDedicated() { return dedicated_; }
    void SetDedicated(bool is_dedicated) { dedicated_ = is_dedicated; }

    virtual void Draw(sf::RenderTarget& rt) = 0;
protected:
    bool dedicated_ = false;
};

#endif // ___FIGURE_H___