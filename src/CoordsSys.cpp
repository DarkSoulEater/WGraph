#include "CoordsSys.h"
#include "Shape.h"
#include <cmath>

CoordsSys::CoordsSys(uint32_t width, uint32_t height) {
    texture_.create(width, height); // TODO: check result
}

void CoordsSys::SetSize(uint32_t width, uint32_t height) {
    texture_.create(width, height);
}

void CoordsSys::SetPosition(float X, float Y) {
    sprite_.setPosition(X, Y);
}

void CoordsSys::SetScale(int32_t scale) {
    const int32_t kMinScale = 2;
    const int32_t kMaxScale = 100;

    scale_ = scale;
    if (scale_ < kMinScale) scale_ = kMinScale;
    if (scale_ > kMaxScale) scale_ = kMaxScale;
}

void CoordsSys::Move(const sf::Vector2f &offset) {
    centre_ -= offset;
}

void CoordsSys::Zoom(float factor) {
    SetScale(scale_ * factor);
}

void CoordsSys::SetBackgroundColor(sf::Color color) {
    background_color_ = color;
}

sf::Vector2f CoordsSys::ToWorldCoords(const sf::Vector2i &screen_coords) const {
    return sf::Vector2f(screen_coords) / (float)scale_ + centre_;
}

sf::Vector2i CoordsSys::ToScreenCoords(const sf::Vector2f &world_coords) const {
    return sf::Vector2i((world_coords - centre_) * (float)scale_);
}

void CoordsSys::DrawGrid(sf::RenderTexture &window) {
    if (!draw_grid_) return;

    const float kEps = 0.0000001f;

    auto size = texture_.getSize();

    sf::Color grid_color = sf::Color::Black;

    // Draw vertical grid line
    for (uint32_t i = 0; i < size.x; ++i) {
        sf::Vector2f coords = ToWorldCoords({i, 0});

        if ((coords.x - std::floor(coords.x)) >= kEps) continue;

        sf::Vertex line[] = {
            sf::Vertex({i, 0}, grid_color),
            sf::Vertex({i, size.y}, grid_color)
        };
        texture_.draw(line, 2, sf::Lines);
    }

    // Draw horizontal grid line
    for (uint32_t i = 0; i < size.x; ++i) {
        sf::Vector2f coords = ToWorldCoords({0, i});

        if ((coords.y - std::floor(coords.y)) >= kEps) continue;

        sf::Vertex line[] = {
            sf::Vertex({0, i}, grid_color),
            sf::Vertex({size.x, i}, grid_color)
        };
        texture_.draw(line, 2, sf::Lines);
    }
}

void CoordsSys::Update() {
    texture_.clear(background_color_);

    Shape* head = Shape::Head_;
    while (head != nullptr) {
        head->Update();
        head = head->next_;
    }
}

void CoordsSys::Draw(sf::RenderWindow &window) {
    texture_.clear(background_color_);

    DrawGrid(texture_);

    Shape* head = Shape::Head_;
    while (head != nullptr) {
        head->Draw(texture_, *this);
        head = head->next_;
    }

    sprite_.setTexture(texture_.getTexture());
    window.draw(sprite_);
}
