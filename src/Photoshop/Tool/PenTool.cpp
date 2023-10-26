#include "PenTool.h"
#include "Photoshop/UI/Canvas/Canvas.h"

void PenTool::OnMainButton(ButtonState state, Vector2 pos, Canvas &canvas) {
    if (state == ButtonState::Released) {
        main_button_pressed = false;
        return;
    }

    BrokenLine* brline = static_cast<BrokenLine*>(canvas.GetActiveFigure());
    if (brline == nullptr) {
        brline = new BrokenLine();
        canvas.DrawFigure(brline);
    }

    Color color = palette_.GetForegroundColor();
    if (!main_button_pressed) {
        main_button_pressed = true;
        brline->AddPoint(pos, color);
    } else {
        sf::Vertex& vert = brline->GetLastVertex();
        vert.position = pos;
    }
}

void PenTool::OnSecondaryButton(ButtonState state, Vector2 pos, Canvas &canvas) {
}

void PenTool::OnConfirm(Canvas &canvas) {
    BrokenLine* brline = static_cast<BrokenLine*>(canvas.GetActiveFigure());
    if (!brline) return;

    canvas.ResetActiveFigure();
}

void PenTool::OnCancel(Canvas &canvas) {
    canvas.DeleteActiveFigure();
}
