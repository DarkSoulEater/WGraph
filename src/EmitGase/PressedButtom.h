#ifndef ___PRESSEDBUTTOM_H___
#define ___PRESSEDBUTTOM_H___

#include <memory>
#include "UI/Widget.h"
#include "SFML/Graphics.hpp"
#include "EmitGase/Animation/Animation.h"
#include "Core/Action/Action.h"

class PressedButtom : public Widget {
public:
    PressedButtom(Action* action = nullptr);

    void OnClick() { if (action_) action_->operator()(); }

    virtual void OnMouseEvent(const MouseEvent& event) override;
    virtual void OnDrawEvent(const DrawEvent& event) override;

    void SetAnimation(Animation* anim);

protected:
    std::shared_ptr<Action> action_;

private:
    std::shared_ptr<Animation> animation_;
};

#endif // ___PRESSEDBUTTOM_H___