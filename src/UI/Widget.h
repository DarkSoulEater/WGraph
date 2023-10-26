#ifndef ___WIDGET_H___
#define ___WIDGET_H___

#include "Core/Object.h"
#include "Core/Event/MouseEvent.h"
#include "Core/Event/DrawEvent.h"
#include "Math/Vector2.h"
#include "Math/FloatRect.h"

class Widget : public Object {
public:
    Widget(Object* parent = nullptr) : Object(parent) {}
    virtual ~Widget() {}

    void SetBoundsSize(const Vector2& bounds_size, bool update_origin = true);
    // FloatRect GetLocalBounds();
    FloatRect GetGlobalBounds();

    void SetOrigin(const Vector2& origin) { origin_ = origin; }
    Vector2 GetOrigin() const { return origin_; }

    virtual void OnEvent(const Event* event) override;

    virtual void OnMouseEvent(const MouseEvent& event) {}
    virtual void OnDrawEvent(const DrawEvent& event);
protected:
    Vector2 bounds_size_ = Vector2(10.f, 10.f);
    Vector2 origin_   = Vector2(0.f, 0.f);
};

#endif // ___WIDGET_H___