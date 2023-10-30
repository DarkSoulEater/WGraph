#ifndef ___CIRCLETOOL_H___
#define ___CIRCLETOOL_H___

#include "Photoshop/Tool/Tool.h"
#include "Photoshop/Canvas/Figure/Circle.h"

class CircleTool : public Tool {
public:
    CircleTool(ToolPalette& palette) : Tool(palette) {}

    virtual void OnMainButton(ButtonState state, Vector2 pos, Canvas& canvas) override;
    // virtual void OnSecondaryButton(ButtonState state, Vector2 pos, Canvas& canvas) override;

    // virtual void OnModifier1(ButtonState state, Vector2 pos, Canvas& canvas) override;
    // virtual void OnModifier2(ButtonState state, Vector2 pos, Canvas& canvas) override;
    // virtual void OnModifier3(ButtonState state, Vector2 pos, Canvas& canvas) override;

    // virtual void OnMove(Vector2 pos, Canvas& canvas) override;
    virtual void OnConfirm(Canvas& canvas) override;
    virtual void OnCancel(Canvas& canvas) override;

private:
    /* data */
};

#endif // ___CIRCLETOOL_H___