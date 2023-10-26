#include "BrokenLine.h"

void BrokenLine::Draw(sf::RenderTarget &rt) {
    for (int i = 0; i < vertexs_.size() - 1; ++i) {
        rt.draw(vertexs_.data() + i, 2, sf::Lines);
    }

    if (dedicated_) {
        for (int i = 0; i < vertexs_.size(); ++i) {
            float R = 5;
            sf::CircleShape circle(5);
            circle.setFillColor(sf::Color::Green);
            circle.setPosition(vertexs_[i].position);
            circle.setOrigin(Vector2(R / 2));
            rt.draw(circle);
        }
    }
}

void BrokenLine::AddPoint(Vector2 point, Color color) {
    vertexs_.push_back(sf::Vertex(point, color));
}
