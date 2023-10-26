#ifndef ___TOOL_H___
#define ___TOOL_H___

#include "UI/Widget.h"
// #include "Photoshop/UI/Canvas/Canvas.h"
#include "Math/Vector2.h"

enum ButtonState {
    Released = 0,
    Pressed = 1
};

class Canvas;
class ToolPalette;

class Tool {
public:
    Tool(ToolPalette& palette) : palette_(palette) {}
    virtual ~Tool() {}

    virtual void OnMainButton(ButtonState state, Vector2 pos, Canvas& canvas)      {};
    virtual void OnSecondaryButton(ButtonState state, Vector2 pos, Canvas& canvas) {};

    virtual void OnModifier1(ButtonState state, Vector2 pos, Canvas& canvas) {};
    virtual void OnModifier2(ButtonState state, Vector2 pos, Canvas& canvas) {};
    virtual void OnModifier3(ButtonState state, Vector2 pos, Canvas& canvas) {};

    virtual void OnMove(Vector2 pos, Canvas& canvas)    {};
    virtual void OnConfirm(Canvas& canvas) {};
    virtual void OnCancel(Canvas& canvas)  {};

    Widget* GetWidget() { return widget_; }

protected:
    Widget* widget_ = nullptr;
    ToolPalette& palette_;
};

#endif // ___TOOL_H___