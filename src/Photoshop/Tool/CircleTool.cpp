#include "CircleTool.h"
#include <cmath>
#include "Photoshop/UI/Canvas/Canvas.h"

void CircleTool::OnMainButton(ButtonState state, Vector2 pos, Canvas &canvas) {
    if (state == ButtonState::Released) {
        OnConfirm(pos, canvas);
        return;
    }

    Circle* circle = static_cast<Circle*>(canvas.GetActiveFigure());
    if (circle == nullptr) {
        circle = new Circle(pos);
        canvas.DrawFigure(circle);
        circle->SetOutlineColor(palette_.GetForegroundColor());
    }

    Vector2 circle_centre = circle->GetCentre();
    circle->SetRadius(std::fabs((circle_centre - pos).Len()));
}

void CircleTool::OnConfirm(Canvas &canvas) {
    Circle* circle = static_cast<Circle*>(canvas.GetActiveFigure());
    if (!circle) return;

    canvas.ResetActiveFigure();
}

void CircleTool::OnCancel(Canvas &canvas) {
    canvas.DeleteActiveFigure();
}
