#ifndef ___PALETTE_H___
#define ___PALETTE_H___

#include "Core/Window.h"
#include "Core/Event/KeyEvent.h"
#include "UI/Widget.h"
#include "Photoshop/Tool/ToolPalette.h"
#include "UI/PushButton.h"
#include "Core/Event/ButtonPressedEvent.h"
#include "Photoshop/Tool/Color.h"

class Palette : public Widget {
public:
    Palette(Window& main_window);

    ToolPalette& GetToolPalette() { return palette_; }

    virtual void OnEvent(const Event* event) override;
    virtual void OnMouseEvent(const MouseEvent& event) override;
    virtual void OnDrawEvent(const DrawEvent& event) override;
    void OnKeyEvent(const KeyEvent& event);
    void OnButtonPressedEvent(const ButtonPressedEvent& event);

private:
    size_t tool_button_cnt = -1;
    size_t tool_active_button = 0;
    std::vector<PushButton*> tool_buttons;

    Color tool_active_button_color = Color(59, 59, 59);
    Color tool_deactive_button_color = Color(0);

private:
    Window& main_window_;
    ToolPalette palette_;
};

#endif // ___PALETTE_H___