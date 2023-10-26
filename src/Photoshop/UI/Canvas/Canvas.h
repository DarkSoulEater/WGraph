#ifndef ___CANVAS_H___
#define ___CANVAS_H___

#include <assert.h>
#include <memory>
#include "UI/Widget.h"
#include "UI/ScrollBar.h"
#include "Core/Event/KeyEvent.h"
#include "Core/Event/BarScrolledEvent.h"
#include "Photoshop/Event/ToolChangedEvent.h"

#include "Photoshop/UI/Canvas/Figure/Figure.h"
#include "Photoshop/Tool/ToolPalette.h"

class Canvas : public Widget {
public:
    Canvas(ToolPalette& palette, Vector2 size, Vector2 position = Vector2(0, 0), Vector2 canvas_size = Vector2(-1, -1));

    virtual void OnEvent(const Event* event) override;
    virtual void OnMouseEvent(const MouseEvent& event) override;
    virtual void OnDrawEvent(const DrawEvent& event) override;
    void OnBarScrolled(const BarScrolledEvent& event);
    void OnToolChangedEvent(const ToolChangedEvent& event);
    void OnKeyEvent(const KeyEvent& event);

private:
    void MoveCanvas(Vector2 delta);

    void DrawPen(const MouseEvent& event);

private:
    struct Node {
        Node(Figure* fig, Node* next = nullptr, Node* prev = nullptr) : figure(fig), next(next), prev(prev) { assert(fig); }
        std::shared_ptr<Figure> figure;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    Node* figures_head_ = nullptr;
    Node* figures_tail_ = nullptr;
    
    ToolPalette& palette_;
    Node* active_figure_ = nullptr;

public:
    void ResetActiveFigure();
    Figure* GetActiveFigure();

    void DrawFigure(Figure* figure);
    void DeleteFigure(std::shared_ptr<Figure> figure) { assert(0); }
    void DeleteActiveFigure();

private:
    Vector2 canvas_size_ = {0, 0};
    
    float bar_thickness = 15;
    std::shared_ptr<ScrollBar> vert_bar;
    std::shared_ptr<ScrollBar> horiz_bar;

private:
    sf::Image image_;
    sf::RenderTexture texture_;

    bool mouse_button_left_pressed = false;
    bool mouse_button_right_pressed = false;
};

#endif // ___CANVAS_H___