#ifndef ___BAR_H___
#define ___BAR_H___

#include <memory>
#include "Math/Vector2.h"
#include "UI/Widget.h"
#include "Core/Action/Action.h"

class Bar : public Widget {
public:
    Bar(const Vector2& position, const Vector2& size, int division, Action* action = nullptr);
    
    virtual void OnMouseEvent(const MouseEvent& event) override;
    virtual void OnDrawEvent(const DrawEvent& event) override;

protected:
    std::shared_ptr<Action> action_;

private:
    float shift_ = 10;
    int division_ = 1;
    int cnt_active_division_ = -1;
    int cnt_dedicated_division_ = -1;

    bool mouse_on_bar_ = false;

    Vector2 size_;
    Vector2 romb_size_ = Vector2(1, 1);

    //sf::RenderTexture texture;
    sf::ConvexShape shape;
};

#endif // ___BAR_H___