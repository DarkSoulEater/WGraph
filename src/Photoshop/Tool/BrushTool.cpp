#include "BrushTool.h"
#include "Photoshop/UI/Canvas/Canvas.h"

void BrushTool::OnMainButton(ButtonState state, Vector2 pos, Canvas &canvas) {
    BrokenLine* brline = static_cast<BrokenLine*>(canvas.GetActiveFigure());

    if (state == ButtonState::Released) {
        if (!brline) return;
        OnConfirm(canvas);
    }

    if (brline == nullptr) {
        brline = new BrokenLine();
        canvas.DrawFigure(brline);
        brline->SetDedicated(false);
    }

    Color color = palette_.GetForegroundColor();
    brline->AddPoint(pos, color);
}

void BrushTool::OnConfirm(Canvas &canvas) {
    BrokenLine* brline = static_cast<BrokenLine*>(canvas.GetActiveFigure());
    if (!brline) return;
    canvas.ResetActiveFigure();
}

void BrushTool::OnCancel(Canvas &canvas) {
    canvas.DeleteActiveFigure();
}
