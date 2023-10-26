#ifndef ___BUTTON_H___
#define ___BUTTON_H___

#include "UI/Widget.h"

class Button : public Widget {
public:
    virtual void OnMouseEvent(const MouseEvent& even) override;
    virtual void OnDrawEvent(const DrawEvent& even) override;

    void OnClick(); 

private:
    sf::RectangleShape rect;
};

#endif // ___BUTTON_H___