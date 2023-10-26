#include "Bar.h"
#include "EmitGase/Event/TemperatureChangeEvent.h"
#include "Core/Action/ActSendEvent.h"

Bar::Bar(const Vector2 &position, const Vector2 &size, int division, Action* action) : division_(division), size_(size), action_(action) {
    //texture.create(size.X, size.Y);
    SetPosition(position);
    SetBoundsSize(size_, false);

    romb_size_ = Vector2(size.X, (size.Y - shift_) / division_ - 1);

    shape.setPointCount(4);
    shape.setPoint(0, Vector2(0));
    shape.setPoint(1, Vector2(romb_size_.X, shift_ - 1));
    shape.setPoint(2, Vector2(romb_size_.X, shift_ + romb_size_.Y - 1));
    shape.setPoint(3, Vector2(0, romb_size_.Y - 1));

    shape.setFillColor(sf::Color::Black);

    //texture.draw(shape);
    //texture.clear();
}

void Bar::OnMouseEvent(const MouseEvent &event) {
    mouse_on_bar_ = GetGlobalBounds().Contains(event.MousePosition);
    if (!mouse_on_bar_) {
        cnt_dedicated_division_ = -1;
        return;
    }

    Vector2 pos = MapFromGlobal(event.MousePosition);

    cnt_dedicated_division_ = int((pos.Y - pos.X / size_.X * shift_) / romb_size_.Y);

    if (event.MouseButton[MouseButtom::kLeft].Pressed) {
        cnt_active_division_ = cnt_dedicated_division_;

        float new_temp = 100 * cnt_active_division_;
        ((ActSendEvent*)action_.get())->event_.reset(new TemperatureChangeEvent(new_temp));
        action_->operator()();
    }
}

void Bar::OnDrawEvent(const DrawEvent &event) {
    for (int i = 0; i < division_; ++i) {
        if (i <= cnt_active_division_) {
            shape.setFillColor(sf::Color(100, 20, 20));
        } else if (i <= cnt_dedicated_division_) {
            shape.setFillColor(sf::Color(80, 20, 60));
        } else {
            shape.setFillColor(sf::Color(0, 0, 0, 150));
        }

        shape.setPosition(position_.X, position_.Y + romb_size_.Y * i);
        event.Window.draw(shape);
    }

    // Widget::OnDrawEvent(event);
}
