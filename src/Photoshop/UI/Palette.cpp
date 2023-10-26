#include "Palette.h"
#include "Photoshop/Tool/PenTool.h"
#include "Photoshop/Tool/BrushTool.h"
#include "Photoshop/Tool/CircleTool.h"
#include "Photoshop/Event/ToolChangedEvent.h"

void Palette::OnEvent(const Event *event) {
    if (event->Type() == EventType::Key) {
        OnKeyEvent(*static_cast<const KeyEvent*>(event));
    }
}

void Palette::OnKeyEvent(const KeyEvent &event) {
    // Change Tool
    Tool* tool = nullptr;
    if (event.Keys[KeyCode::P].Pressed) {
        std::cout << "LOG[Palette]: Set Pen Tool\n";
        tool = new PenTool(palette_);
    } else if (event.Keys[KeyCode::B].Pressed) {
        std::cout << "LOG[Palette]: Set Brash Tool\n";
        tool = new BrushTool(palette_);
    } else if (event.Keys[KeyCode::C].Pressed) {
        std::cout << "LOG[Palette]: Set Circle Tool\n";
        tool = new CircleTool(palette_);
    }

    if (tool) {
        ToolChangedEvent event;
        main_window_.OnEvent(&event);

        palette_.ResetTool(tool);
    }

    // Change Color
    if (event.Keys[KeyCode::W].Pressed) {
        std::cout << "LOG[Palette]: Set White foreground color\n";
        palette_.SetForegroundColor(Color::White);
    } else if (event.Keys[KeyCode::Y].Pressed) {
        std::cout << "LOG[Palette]: Set Yellow foreground color\n";
        palette_.SetForegroundColor(Color::Yellow);
    } else if (event.Keys[KeyCode::M].Pressed) {
        std::cout << "LOG[Palette]: Set Magneta foreground color\n";
        palette_.SetForegroundColor(Color::Magenta);
    }
}
