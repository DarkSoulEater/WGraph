#include "Clock.h"

Clock::Clock() {
    float scale = 0.1f;

    sf::Image dial_image;
    if (!dial_image.loadFromFile("assets/Clock/dial.png")) {
        std::cerr << "Warning[Clock]: Fail load Dial texture\n";
    }
    int color_mask = 200;
    for (int j = 0; j < dial_image.getSize().y; ++j) {
        for (int i = 0; i < dial_image.getSize().x; ++i) {
            sf::Color color = dial_image.getPixel(i, j);
            if (color.r > color_mask && color.g > color_mask && color.b > color_mask) {
                dial_image.setPixel(i, j, sf::Color(0));
            }
        }
    }
    dial_texture_.loadFromImage(dial_image);
    dial_.setTexture(dial_texture_);
    dial_.setScale(scale, scale);

    if (!hour_hand_texture_.loadFromFile("assets/Clock/hour_hand.png")) {
        std::cerr << "Warning[Clock]: Fail load Hour hand texture\n";
    }
    hour_hand_.setTexture(hour_hand_texture_);
    hour_hand_.setScale(scale, scale);
    hour_hand_.setOrigin(50, 50 + 40);
    hour_hand_.rotate(-90);

    if (!minute_hand_texture_.loadFromFile("assets/Clock/minute_hand.png")) {
        std::cerr << "Warning[Clock]: Fail load Minute hand texture\n";
    }
    minute_hand_.setTexture(minute_hand_texture_);
    minute_hand_.setScale(scale, scale);
    minute_hand_.setOrigin(20 + 73, 910 + 72);
    minute_hand_.rotate(1.5);
}

void Clock::OnDrawEvent(const DrawEvent &event) {
    dial_.setPosition(MapToGlobal());
    event.Window.draw(dial_);

    auto bounds = dial_.getGlobalBounds();

    // sf::Vertex Line[] {
    //     sf::Vertex(MapToGlobal({bounds.getSize().x / 2, 0})),
    //     sf::Vertex(MapToGlobal({bounds.getSize().x / 2, bounds.getSize().y}))
    // };
    // event.Window.draw(Line, 2, sf::Lines);

    // Line[0] = sf::Vertex(MapToGlobal({0, bounds.getSize().y / 2}));
    // Line[1] = sf::Vertex(MapToGlobal({bounds.getSize().x, bounds.getSize().y / 2}));
    // event.Window.draw(Line, 2, sf::Lines);

    minute_hand_.rotate(event.DrawDeltaTime * 360);
    minute_hand_.setPosition(MapToGlobal({sf::Vector2f(bounds.getSize()) / 2.f}));
    event.Window.draw(minute_hand_);

    hour_hand_.rotate(event.DrawDeltaTime * 30);
    hour_hand_.setPosition(MapToGlobal({sf::Vector2f(bounds.getSize()) / 2.f}));
    event.Window.draw(hour_hand_);

}
