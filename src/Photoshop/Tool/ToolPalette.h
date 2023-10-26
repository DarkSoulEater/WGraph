#ifndef ___TOOLPALETTE_H___
#define ___TOOLPALETTE_H___

#include "Photoshop/Tool/Tool.h"
#include "Photoshop/Tool/PenTool.h"
#include "Photoshop/Tool/Color.h"

class ToolPalette {
public:
    ToolPalette() {}

    Tool& GetActiveTool() const { return *active_tool_; }

    void ResetTool(Tool* new_tool) {
        delete active_tool_;
        active_tool_ = new_tool;
    }

    void  SetForegroundColor(Color color) { foreground_color_ = color; }
    Color GetForegroundColor()            { return foreground_color_; }
    void  SetBackgroundColor(Color color) { background_color_ = color; }
    Color GetBackgroundColor()            { return background_color_; }

private:
    Color foreground_color_ = Color::White;
    Color background_color_ = Color::Yellow;
    Tool* active_tool_ = new PenTool(*this);
};

#endif // ___TOOLPALETTE_H___