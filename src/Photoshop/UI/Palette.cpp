#include "Palette.h"
#include "Photoshop/Tool/PenTool.h"
#include "Photoshop/Tool/BrushTool.h"
#include "Photoshop/Tool/CircleTool.h"
#include "Photoshop/Event/ToolChangedEvent.h"

#include "Core/Action/AcDebug.h"
#include "Core/Action/ActSendEvent.h"

#include "Print.h"

Palette::Palette(Window &main_window) : main_window_(main_window) {
    SetPosition({10, 50});
    SetBoundsSize({144, 600}, false);

    tool_button_cnt = palette_.GetToolsCount();

    for (size_t i = 0; i < tool_button_cnt; ++i) {
        Vector2 button_size(66, 52);
        tool_buttons.push_back(new PushButton(button_size));
        tool_buttons[i]->SetParent(this);
        tool_buttons[i]->SetPosition(Vector2(6  + button_size.X * (i % 2), 
                                             10 + button_size.Y * (i / 2)));
        tool_buttons[i]->SetAction(new ActSendEvent(new ButtonPressedEvent(tool_buttons[i], i), this));
    }

    tool_buttons[0]->UpdateTexture("assets/Tool/PenTool.png");
    tool_buttons[1]->UpdateTexture("assets/Tool/BrushTool.png");
    tool_buttons[2]->UpdateTexture("assets/Tool/CircleTool.png");

    tool_buttons[tool_active_button]->SetColor(tool_active_button_color);
}

void Palette::OnEvent(const Event *event) {
    if (event->Type() == EventType::Key) {
        OnKeyEvent(*static_cast<const KeyEvent*>(event));
    } else if (event->Type() == EventType::ButtonPressed) {
        OnButtonPressedEvent(*static_cast<const ButtonPressedEvent*>(event));
        return;
    }

    Widget::OnEvent(event);
}

void Palette::OnMouseEvent(const MouseEvent &event) {
}

void Palette::OnDrawEvent(const DrawEvent &event) {
    sf::RectangleShape panel;
    panel.setFillColor(Color(79, 79, 79));
    panel.setOutlineColor(Color(35, 35, 35));
    panel.setOutlineThickness(-2);
    panel.setPosition(MapToGlobal());
    panel.setSize(Vector2(144, 600));
    event.Window.draw(panel);

    // Widget::OnDrawEvent(event);
}

void Palette::OnKeyEvent(const KeyEvent &event) {
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

void Palette::OnButtonPressedEvent(const ButtonPressedEvent &event) {
    // Log("Pressed: %d", event.Index);
    
    if (palette_.IsNowTool(event.Index)) {
        ToolChangedEvent tool_event;
        main_window_.OnEvent(&tool_event);
        palette_.ResetTool(event.Index);

        tool_buttons[tool_active_button]->SetColor(tool_deactive_button_color);
        tool_buttons[event.Index]->SetColor(tool_active_button_color);
        tool_active_button = event.Index;

        switch (event.Index) {
            case 0: {
                Log("[Pallete] Switch to Pen Tool");
            } break;

            case 1: {
                Log("[Pallete] Switch to Brush Tool");
            } break;

            case 2: {
                Log("[Pallete] Switch to Circle Tool");
            } break;

            default: {
                Log("[Pallete] Switch to Unknow Tool");
            } break;
        }
    }
}
