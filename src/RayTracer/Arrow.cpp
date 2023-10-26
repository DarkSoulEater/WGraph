#include "Arrow.h"
#include "SFML/Graphics.hpp"

void Arrow::SetColor(sf::Color color) {
    color_ = color;
}

void Arrow::Rotate(float angle) {
    Vector2 dir = end_ - begin_;
    dir.Rotate(angle);
    end_ = begin_ + dir;
}

void Arrow::Update() {
    Rotate(0.1f);
}

void Arrow::Draw(sf::RenderTexture &window, const CoordsSys& coords_sys) {
    // TODO: It is cringe
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(coords_sys.ToScreenCoords((sf::Vector2f)begin_)), color_),
        sf::Vertex(sf::Vector2f(coords_sys.ToScreenCoords((sf::Vector2f)end_)),   color_)
    };
    window.draw(line, 2, sf::Lines);

    Vector2 dir = Vector2::Normalize(end_ - begin_);

    sf::Vertex line_ear[] = {
        sf::Vertex(sf::Vector2f(coords_sys.ToScreenCoords((sf::Vector2f)end_)), color_),
        sf::Vertex(sf::Vector2f(coords_sys.ToScreenCoords((sf::Vector2f) (end_ + (dir.Normal() - dir) * 1))), color_)
    };
    window.draw(line_ear, 2, sf::Lines);

    line_ear[1] = sf::Vertex(sf::Vector2f(coords_sys.ToScreenCoords((sf::Vector2f) (end_ + (-dir.Normal() - dir) * 1))), color_);
    window.draw(line_ear, 2, sf::Lines);
}