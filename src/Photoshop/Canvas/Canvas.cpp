#include "Canvas.h"
#include <assert.h>
#include <cmath>

// Canvas::Canvas(ToolPalette& palette, Vector2 size, Vector2 position, Vector2 canvas_size) : palette_(palette) {
    // assert(size.X > 0 && size.Y > 0 && "Canvas size must be more 0");
    // canvas_size_ = size * 2.f; // TODO:

    // vert_bar.reset(new ScrollBar(ScrollBar::Type::kVertical, {bar_thickness, size.Y - bar_thickness - 1}));
    // vert_bar->SetParent(this);
    // vert_bar->SetMaxValue(canvas_size_.Y - size.Y);
    // vert_bar->SetPosition({size.Y - bar_thickness , 0});

    // horiz_bar.reset(new ScrollBar(ScrollBar::Type::kHorizontal, {size.X, bar_thickness}));
    // horiz_bar->SetParent(this);
    // horiz_bar->SetMaxValue(canvas_size_.X - size.X);
    // horiz_bar->SetPosition({0, size.Y - bar_thickness});

    // SetBoundsSize(size, false);

    // texture_.create(size.X + 1, size.Y + 1, false);

    // SetPosition(position);
// }

// void Canvas::OnEvent(const Event *event) {
//     if (event->Type() == EventType::BarScrolled) {
//         OnBarScrolled(*static_cast<const BarScrolledEvent*>(event));
//         return;
//     } else if (event->Type() == EventType(kUserEventToolChanged)) {
//         OnToolChangedEvent(*static_cast<const ToolChangedEvent*>(event));
//         return;
//     } else if (event->Type() == EventType::Key) {
//         OnKeyEvent(*static_cast<const KeyEvent*>(event));
//     }
//     Widget::OnEvent(event);
// }

// void Canvas::OnMouseEvent(const MouseEvent &event) {
//     Tool& active_tool = palette_.GetActiveTool();

//     if (event.MouseButton[MouseButtom::kLeft].Released)  { 
//         mouse_button_left_pressed = false;

//         active_tool.OnMainButton(ButtonState::Released, texture_.mapPixelToCoords(MapFromGlobal(event.MousePosition)), *this);
//     }
//     if (event.MouseButton[MouseButtom::kRight].Released) {
//         mouse_button_right_pressed = false; 

//         active_tool.OnSecondaryButton(ButtonState::Released, texture_.mapPixelToCoords(MapFromGlobal(event.MousePosition)), *this);
//     }

//     if (mouse_button_right_pressed) {
//         MoveCanvas(event.DeltaMouse);
//         return;
//     }

//     if (!GetGlobalBounds().Contains(event.MousePosition)) { return; }

//     if (event.MouseButton[MouseButtom::kLeft].Pressed)  { 
//         auto mouse_pos = MapFromGlobal(event.MousePosition);
//         auto size = texture_.getSize();
//         if (mouse_pos.X < size.x - bar_thickness && mouse_pos.Y < size.y - bar_thickness) {
//             mouse_button_left_pressed = true;  
//         }
//     }
//     if (event.MouseButton[MouseButtom::kRight].Pressed) { mouse_button_right_pressed = true; }

//     if (mouse_button_left_pressed) {
//         active_tool.OnMainButton(ButtonState::Pressed, texture_.mapPixelToCoords(MapFromGlobal(event.MousePosition)), *this);
//     }

//     if (mouse_button_right_pressed) {
//         active_tool.OnSecondaryButton(ButtonState::Pressed, texture_.mapPixelToCoords(MapFromGlobal(event.MousePosition)), *this);
//     }
// }

// void Canvas::OnDrawEvent(const DrawEvent &event) {
//     sf::RectangleShape frame(sf::Vector2f(texture_.getSize()) - sf::Vector2f(2, 1));
//     frame.setFillColor(sf::Color(0));
//     frame.setOutlineColor(sf::Color(79, 79, 79));
//     frame.setOutlineThickness(1.f);
//     frame.setPosition(1, 1);

//     texture_.clear(sf::Color::Black);
//     // Draw all figures
//     GetLayer().Draw(texture_);
//     // Node* node = figures_head_;
//     // while (node) {
//     //     node->figure->Draw(texture_);
//     //     node = node->next;
//     // }

//     // Draw frame
//     sf::View view = texture_.getView();
//     texture_.setView(texture_.getDefaultView());
//     texture_.draw(frame);
//     texture_.setView(view);

//     texture_.display();

//     sf::Sprite sprite(texture_.getTexture());
//     sprite.setPosition(MapToGlobal());
//     event.Window.draw(sprite);
// }

// void Canvas::OnBarScrolled(const BarScrolledEvent &event) {
//     ScrollBar::Type type = event.Bar->GetType();
//     sf::View canvas_view = texture_.getView();
//     auto canvas_centre = canvas_view.getCenter();
//     auto size = texture_.getSize();

//     Vector2 move = {0, 0};
//     if (type == ScrollBar::Type::kVertical) {
//         move = Vector2(event.Value + size.y / 2) - canvas_centre;
//         move.X = 0;
//     } else {
//         move = Vector2(event.Value + size.x / 2) - canvas_centre;
//         move.Y = 0;
//     }
//     MoveCanvas(-move);
// }

// void Canvas::OnKeyEvent(const KeyEvent &event) {
//     Tool& active_tool = palette_.GetActiveTool();
//     if (event.Keys[KeyCode::Enter].Pressed) {
//         active_tool.OnConfirm(*this);
//     }

//     if (event.Keys[KeyCode::Escape].Pressed) {
//         active_tool.OnCancel(*this);
//     }
// }

// void Canvas::MoveCanvas(Vector2 delta) {
//     sf::View canvas_view = texture_.getView();
//     canvas_view.move(-delta);

//     if (canvas_size_.X > 0 && canvas_size_.Y > 0) {
//         auto size = texture_.getSize();
//         auto canvas_centre = canvas_view.getCenter();

//         canvas_centre.x = std::max(size.x / 2.f, canvas_centre.x);
//         canvas_centre.y = std::max(size.y / 2.f, canvas_centre.y);

//         canvas_centre.x = std::min(canvas_size_.X - size.x / 2.f, canvas_centre.x);
//         canvas_centre.y = std::min(canvas_size_.Y - size.y / 2.f, canvas_centre.y);
        
        
//         canvas_view.setCenter(canvas_centre);

//         if (vert_bar)  { vert_bar->UpdateValue(canvas_centre.y - size.y / 2.f); }
//         if (horiz_bar) { horiz_bar->UpdateValue(canvas_centre.x - size.x / 2.f); }
//     }

//     texture_.setView(canvas_view);
// }


Canvas::Canvas(ToolPalette &palette, Vector2 canvas_size) : palette_(palette), canvas_size_(canvas_size), layer1_(Vector2(canvas_size)) {

}
