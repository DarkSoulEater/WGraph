#ifndef ___PANEL_H___
#define ___PANEL_H___

#include "UI/Widget.h"

class Panel : public Widget {
public:
    Panel();

    virtual void OnDrawEvent(const DrawEvent& event);

private:
    sf::Texture texture_;
    sf::Sprite sprite_;
};

#endif // ___PANEL_H___