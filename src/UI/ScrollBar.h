#ifndef ___SCROLLBAR_H___
#define ___SCROLLBAR_H___

#include "UI/Widget.h"
#include "UI/PushButton.h"
#include "Core/Action/Action.h"
#include "Core/Event/ButtonPressedEvent.h"

class ScrollBar : public Widget {
public:
    enum class Type {
        kVertical,
        kHorizontal
    };

    ScrollBar(Type type, Vector2 size, Vector2 pos = {0, 0});

    Type GetType() { return type_; }

    void SetMaxValue(float value) { max_value_ = value; }
    float GetValue();
    void UpdateValue(float new_value);

    void OnScroll();

    virtual void OnEvent(const Event* event) override;
    virtual void OnMouseEvent(const MouseEvent& event) override;
    virtual void OnDrawEvent(const DrawEvent& event) override;
    void OnButtonPressed(const ButtonPressedEvent& event);

private:
    Vector2 size_;
    float max_value_ = 0.f;

    float slider_len_ = 0.f;
    bool slider_clamped_ = false;
    PushButton slider_;

    Type type_;

private:
    void MoveSlider(Vector2 pos);
};

#endif // ___SCROLLBAR_H___