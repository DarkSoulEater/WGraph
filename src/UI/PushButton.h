#ifndef ___PUSHBUTTON_H___
#define ___PUSHBUTTON_H___

#include <memory>
#include "UI/Widget.h"
#include "Core/Action/Action.h"
#include "Core/Animation/Animation.h"

class PushButton : public Widget {
public:
    PushButton();
    PushButton(Vector2 size, Vector2 position = {0, 0});

    void OnClick();

    void SetAction(Action* action);

    virtual void OnMouseEvent(const MouseEvent& event) override;
    virtual void OnDrawEvent(const DrawEvent& event) override;

protected:
    sf::Image image_;
    sf::Texture texture_;
    sf::Sprite sprite_;

protected:
    std::shared_ptr<Action> action_;
    //std::shared_ptr<Animation> animation_;
};

#endif // ___PUSHBUTTON_H___