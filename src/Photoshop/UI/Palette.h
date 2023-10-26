#ifndef ___PALETTE_H___
#define ___PALETTE_H___

#include "Core/Window.h"
#include "UI/Widget.h"
#include "Photoshop/Tool/ToolPalette.h"
#include "Core/Event/KeyEvent.h"

class Palette : public Widget {
public:
    Palette(Window& main_window) : main_window_(main_window) {}

    ToolPalette& GetToolPalette() { return palette_; }

    virtual void OnEvent(const Event* event) override;

    void OnKeyEvent(const KeyEvent& event);

private:
    Window& main_window_;
    ToolPalette palette_;
};

#endif // ___PALETTE_H___