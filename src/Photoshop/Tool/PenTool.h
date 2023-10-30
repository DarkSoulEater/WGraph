#ifndef ___PENTOOL_H___
#define ___PENTOOL_H___

#include "Photoshop/Tool/Tool.h"
#include "Photoshop/Canvas/Figure/BrokenLine.h"

class PenTool : public Tool {
public:
    PenTool(ToolPalette& palette) : Tool(palette) {}

    virtual void OnMainButton(ButtonState state, Vector2 pos, Canvas& canvas) override;
    virtual void OnSecondaryButton(ButtonState state, Vector2 pos, Canvas& canvas) override;

    // virtual void OnModifier1(ButtonState state, Canvas& canvas) override;
    // virtual void OnModifier2(ButtonState state, Canvas& canvas) override;
    // virtual void OnModifier3(ButtonState state, Canvas& canvas) override;

    // virtual void OnMove(Vector2 pos, Canvas& canvas) override;
    virtual void OnConfirm(Canvas& canvas) override;
    virtual void OnCancel(Canvas& canvas) override;

private:
    bool main_button_pressed = false;
};

#endif // ___PENTOOL_H___