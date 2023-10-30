#include "BrushTool.h"
#include "Photoshop/Canvas/Canvas.h"

void BrushTool::OnMainButton(ButtonState state, Vector2 pos, Canvas &canvas) {
    BrokenLine* brline = static_cast<BrokenLine*>(canvas.GetLayer().GetActiveFigure());

    if (state == ButtonState::Released) {
        if (!brline) return;
        OnConfirm(canvas);
        return;
    }

    if (brline == nullptr) {
        brline = new BrokenLine();
        canvas.GetLayer().AddFigure(brline);
        brline->SetDedicated(false);
    }

    Color color = palette_.GetForegroundColor();
    brline->AddPoint(pos, color);
}

void BrushTool::OnConfirm(Canvas &canvas) {
    BrokenLine* brline = static_cast<BrokenLine*>(canvas.GetLayer().GetActiveFigure());
    if (!brline) return;
    canvas.GetLayer().ResetActiveFigure();
}

void BrushTool::OnCancel(Canvas &canvas) {
    canvas.GetLayer().DeleteActiveFigure();
}
