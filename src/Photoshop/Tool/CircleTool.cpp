#include "CircleTool.h"
#include <cmath>
#include "Photoshop/Canvas/Canvas.h"

void CircleTool::OnMainButton(ButtonState state, Vector2 pos, Canvas &canvas) {
    if (state == ButtonState::Released) {
        OnConfirm(canvas);
        return;
    }

    Circle* circle = static_cast<Circle*>(canvas.GetLayer().GetActiveFigure());
    if (circle == nullptr) {
        circle = new Circle(pos);
        canvas.GetLayer().AddFigure(circle);
        circle->SetOutlineColor(palette_.GetForegroundColor());
    }

    Vector2 circle_centre = circle->GetCentre();
    circle->SetRadius(std::fabs((circle_centre - pos).Len()));
}

void CircleTool::OnConfirm(Canvas &canvas) {
    Circle* circle = static_cast<Circle*>(canvas.GetLayer().GetActiveFigure());
    if (!circle) return;

    canvas.GetLayer().ResetActiveFigure();
}

void CircleTool::OnCancel(Canvas &canvas) {
    canvas.GetLayer().DeleteActiveFigure();
}
