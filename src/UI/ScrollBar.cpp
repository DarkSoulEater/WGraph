#include "ScrollBar.h"
#include <assert.h>
#include "Core/Action/ActSendEvent.h"
#include "Core/Event/BarScrolledEvent.h"

ScrollBar::ScrollBar(Type type, Vector2 size, Vector2 pos)
    :   type_(type), 
        size_(size),
        slider_len_((type == Type::kVertical ? size.Y / 3 : size.X / 3)), 
        slider_((type == Type::kVertical ? Vector2(size.X, slider_len_) : Vector2(slider_len_, size.Y))) {
    SetPosition(position_);
    SetBoundsSize(size_, false);

    slider_.SetParent(this);
    slider_.SetAction(new ActSendEvent(new ButtonPressedEvent(&slider_), this));
}

float ScrollBar::GetValue() {
    auto slider_pos = slider_.GetPosition();
    return type_ == Type::kVertical 
                    ? slider_pos.Y / (size_.Y - slider_len_) * max_value_
                    : slider_pos.X / (size_.X - slider_len_) * max_value_;
}

void ScrollBar::UpdateValue(float new_value) {
    assert(new_value >= 0 && new_value <= max_value_ && "Error[Scroll Bar]: Uncorrect new value");
    auto slider_pos = slider_.GetPosition();
    if (type_ == Type::kVertical) {
        slider_pos.Y = new_value * (size_.Y - slider_len_) / max_value_;
    } else {
        slider_pos.X = new_value * (size_.X - slider_len_) / max_value_;
    }
    slider_.SetPosition(slider_pos);
}

void ScrollBar::OnScroll() {
    Object* parent = GetParent();
    if (parent) {
        BarScrolledEvent event(this, GetValue(), max_value_);
        parent->OnEvent(&event);
    }
}

void ScrollBar::OnEvent(const Event *event) {
    if (event->Type() == EventType::ButtonPressed) {
        OnButtonPressed(*static_cast<const ButtonPressedEvent*>(event));
        return;
    }

    Widget::OnEvent(event);
}

void ScrollBar::OnMouseEvent(const MouseEvent &event) {
    if (event.MouseButton[MouseButtom::kLeft].Released) {
        slider_clamped_ = false;
    }

    if (slider_clamped_) {
        MoveSlider(event.DeltaMouse);
    }
}

void ScrollBar::OnDrawEvent(const DrawEvent &event) {
    sf::RectangleShape shape(size_);
    shape.setOutlineColor(sf::Color(79, 79, 79));
    shape.setOutlineThickness(1);

    shape.setFillColor(sf::Color(30, 30, 30));

    shape.setPosition(MapToGlobal());
    event.Window.draw(shape);
}

void ScrollBar::OnButtonPressed(const ButtonPressedEvent &event) {
    slider_clamped_ = true;
}

void ScrollBar::MoveSlider(Vector2 delta) {
    if (type_ == Type::kVertical) {
        slider_.Move({0, delta.Y});
        auto slider_pos = slider_.GetPosition();
        slider_pos.Y = std::max(0.f, slider_pos.Y);
        slider_pos.Y = std::min(size_.Y - slider_len_, slider_pos.Y);
        slider_.SetPosition(slider_pos);
    } else {
        slider_.Move({delta.X, 0});
        auto slider_pos = slider_.GetPosition();
        slider_pos.X = std::max(0.f, slider_pos.X);
        slider_pos.X = std::min(size_.X - slider_len_, slider_pos.X);
        slider_.SetPosition(slider_pos);
    }

    OnScroll();
}
