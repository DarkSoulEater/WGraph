#ifndef ___TOOLPALETTE_H___
#define ___TOOLPALETTE_H___

#include <assert.h>
#include "Photoshop/Tool/Tool.h"
#include "Photoshop/Tool/PenTool.h"
#include "Photoshop/Tool/BrushTool.h"
#include "Photoshop/Tool/CircleTool.h"
#include "Photoshop/Tool/Color.h"

class ToolPalette {
public:
    ToolPalette() {
        tools_.push_back(new PenTool(*this));
        tools_.push_back(new BrushTool(*this));
        tools_.push_back(new CircleTool(*this));

        active_tool_ = tools_[0];
    }

    ~ToolPalette() {
        for (auto tool : tools_) {
            delete tool;
        }
    }

    size_t GetToolsCount() const { return tools_.size(); }

    Tool& GetActiveTool() const { return *active_tool_; }

    bool ResetTool(Tool* new_tool) {
        if (new_tool == active_tool_) return 0;
        active_tool_ = new_tool;
        return 1;
    }

    bool ResetTool(size_t tool_id) {
        assert(tool_id < GetToolsCount());
        return ResetTool(tools_[tool_id]);
    }

    bool IsNowTool(size_t tool_id) {
        assert(tool_id < GetToolsCount());
        if (tools_[tool_id] == active_tool_) return 0;
        return 1;
    }

    void  SetForegroundColor(Color color) { foreground_color_ = color; }
    Color GetForegroundColor()            { return foreground_color_; }
    void  SetBackgroundColor(Color color) { background_color_ = color; }
    Color GetBackgroundColor()            { return background_color_; }

private:
    Color foreground_color_ = Color::White;
    Color background_color_ = Color::Yellow;
    Tool* active_tool_;
    std::vector<Tool*> tools_;
};

#endif // ___TOOLPALETTE_H___