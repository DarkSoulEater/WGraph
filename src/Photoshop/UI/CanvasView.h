#ifndef ___CANVASVIEW_H___
#define ___CANVASVIEW_H___

#include <assert.h>
#include <memory>
#include "UI/Widget.h"
#include "UI/ScrollBar.h"

#include "Core/Event/KeyEvent.h"
#include "Core/Event/BarScrolledEvent.h"
#include "Photoshop/Event/ToolChangedEvent.h"
#include "Photoshop/Tool/ToolPalette.h"
#include "Photoshop/Filter/FilterPalette.h"
#include "Photoshop/Canvas/Canvas.h"

class CanvasView : public Widget {
public:
    CanvasView(ToolPalette& palette, FilterPalette& filter_palette, Vector2 size, Vector2 position = Vector2(0, 0), Vector2 canvas_size = Vector2(-1, -1));

    virtual void OnEvent(const Event* event) override;
    virtual void OnDrawEvent(const DrawEvent& event) override;
    virtual void OnMouseEvent(const MouseEvent& event) override;
    void OnBarScrolled(const BarScrolledEvent& event) {}
    void OnToolChangedEvent(const ToolChangedEvent& event);
    void OnKeyEvent(const KeyEvent& event);

private:
    void MoveCanvas(Vector2 delta);

private:
    Canvas canvas_;
    ToolPalette& palette_;
    FilterPalette& filter_palette_;

private:
    Vector2 canvas_size_ = {0, 0};
    
    float bar_thickness = 15;
    std::shared_ptr<ScrollBar> vert_bar;
    std::shared_ptr<ScrollBar> horiz_bar;

private:
    sf::Image image_;
    sf::RenderTexture texture_;

    bool mbl_pressed_ = false;
    bool mbr_pressed_ = false;
};

#endif // ___CANVASVIEW_H___