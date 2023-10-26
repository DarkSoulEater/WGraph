#ifndef ___CLOCK_H___
#define ___CLOCK_H___


#include "UI/Widget.h"

class Clock : public Widget {
public:
    Clock();
    
    virtual void OnMouseEvent(const MouseEvent& event) override {}
    virtual void OnDrawEvent(const DrawEvent& event) override;

private:
    sf::Texture dial_texture_;
    sf::Sprite dial_;

    sf::Texture hour_hand_texture_;
    sf::Sprite hour_hand_;

    sf::Texture minute_hand_texture_;
    sf::Sprite minute_hand_;

    const float kPI = 3.1415f;
};

#endif // ___CLOCK_H___