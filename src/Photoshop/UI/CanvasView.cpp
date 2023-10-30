#include "CanvasView.h"

CanvasView::CanvasView(ToolPalette &palette, FilterPalette& filter_palette, Vector2 size, Vector2 position, Vector2 canvas_size) : canvas_(palette, size * 2), palette_(palette), filter_palette_(filter_palette) {
    SetBoundsSize(size, false);
    SetPosition(position);

    texture_.create(size.X + 1, size.Y + 1, false);

    canvas_size_ = size * 2.f; // TODO:
    canvas_size_ = canvas_.GetLayer().GetSize();

    vert_bar.reset(new ScrollBar(ScrollBar::Type::kVertical, {bar_thickness, size.Y - bar_thickness - 1}));
    //vert_bar->SetParent(this);
    vert_bar->SetMaxValue(canvas_size_.Y - size.Y);
    vert_bar->SetPosition({size.Y - bar_thickness , 0});

    horiz_bar.reset(new ScrollBar(ScrollBar::Type::kHorizontal, {size.X, bar_thickness}));
    //horiz_bar->SetParent(this);
    horiz_bar->SetMaxValue(canvas_size_.X - size.X);
    horiz_bar->SetPosition({0, size.Y - bar_thickness});
}

void CanvasView::OnEvent(const Event *event) {
    if (event->Type() == EventType::BarScrolled) {
        OnBarScrolled(*static_cast<const BarScrolledEvent*>(event));
        return;
    } else if (event->Type() == EventType(kUserEventToolChanged)) {
        OnToolChangedEvent(*static_cast<const ToolChangedEvent*>(event));
        return;
    } else if (event->Type() == EventType::Key) {
        OnKeyEvent(*static_cast<const KeyEvent*>(event));
    }
    Widget::OnEvent(event);
}

void CanvasView::OnDrawEvent(const DrawEvent &event) {
    sf::RectangleShape frame(sf::Vector2f(texture_.getSize()) - sf::Vector2f(2, 1));
    frame.setFillColor(sf::Color(10, 10, 10));
    frame.setOutlineColor(sf::Color(79, 79, 79));
    frame.setOutlineThickness(1.f);
    frame.setPosition(MapToGlobal());
    event.Window.draw(frame);

    texture_.clear(sf::Color::Black);
    canvas_.GetLayer().Draw(texture_);
    texture_.display();

    // sf::View view = texture_.getView();
    // texture_.setView(texture_.getDefaultView());
    // texture_.draw(frame);
    // texture_.setView(view);

    // texture_.display();

    sf::Sprite sprite(texture_.getTexture());
    sprite.setPosition(MapToGlobal());
    event.Window.draw(sprite);
}

void CanvasView::OnMouseEvent(const MouseEvent &event) {
    Tool& active_tool = palette_.GetActiveTool();

    if (event.MouseButton[MouseButtom::kLeft].Released) {
        if (mbl_pressed_) {
            Vector2 position_in_canvas = texture_.mapPixelToCoords(MapFromGlobal(event.MousePosition));
            active_tool.OnMainButton(ButtonState::Released, position_in_canvas, canvas_);
        }
        mbl_pressed_ = false;
    }

    if (event.MouseButton[MouseButtom::kRight].Released) {
        mbr_pressed_ = false;
    }

    if (mbr_pressed_) {
        MoveCanvas(event.DeltaMouse);
        return;
    }

    if (!GetGlobalBounds().Contains(event.MousePosition)) 
        return;

    if (event.MouseButton[MouseButtom::kLeft].Pressed) {
        mbl_pressed_ = true;
    }

    if (event.MouseButton[MouseButtom::kRight].Pressed) {
        mbr_pressed_ = true;
    }

    if (mbl_pressed_) {
        Vector2 position_in_canvas = texture_.mapPixelToCoords(MapFromGlobal(event.MousePosition));
        active_tool.OnMainButton(ButtonState::Pressed, position_in_canvas, canvas_);
    }
}

void CanvasView::OnToolChangedEvent(const ToolChangedEvent &event) {
    Tool& active_tool = palette_.GetActiveTool();
    active_tool.OnConfirm(canvas_);
}

void CanvasView::OnKeyEvent(const KeyEvent &event) {
    Tool& active_tool = palette_.GetActiveTool();
    if (event.Keys[KeyCode::Enter].Pressed) {
        active_tool.OnConfirm(canvas_);
    }

    if (event.Keys[KeyCode::Escape].Pressed) {
        active_tool.OnCancel(canvas_);
    }

    if (event.Keys[KeyCode::F].Pressed) {
        FilterMask filter_mask(canvas_size_.X, canvas_size_.Y);
        filter_palette_.GetFilter(0)->ApplyFilter(canvas_, filter_mask);
    }
}

void CanvasView::MoveCanvas(Vector2 delta) {
    sf::View canvas_view = texture_.getView();
    canvas_view.move(-delta);

    if (canvas_size_.X > 0 && canvas_size_.Y > 0) {
        auto size = texture_.getSize();
        auto canvas_centre = canvas_view.getCenter();

        canvas_centre.x = std::max(size.x / 2.f, canvas_centre.x);
        canvas_centre.y = std::max(size.y / 2.f, canvas_centre.y);

        canvas_centre.x = std::min(canvas_size_.X - size.x / 2.f, canvas_centre.x);
        canvas_centre.y = std::min(canvas_size_.Y - size.y / 2.f, canvas_centre.y);
        
        
        canvas_view.setCenter(canvas_centre);

        if (vert_bar)  { vert_bar->UpdateValue(canvas_centre.y - size.y / 2.f); }
        if (horiz_bar) { horiz_bar->UpdateValue(canvas_centre.x - size.x / 2.f); }
    }

    texture_.setView(canvas_view);
}
