#include "Layer.h"

Layer::Layer(Vector2 size) : size_(size) {
    sf::Image image;
    image.loadFromFile("assets/mountine.jpg");
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sp(texture);

    size_ = sf::Vector2f(image.getSize());

    texture_.create(size_.X, size_.Y, false);
    texture_.clear(sf::Color::Blue);
    
    texture_.draw(sp);
    texture_.display();
}

void Layer::Draw(sf::RenderTarget &texture) {
    sf::Sprite sp(texture_.getTexture());
    texture.draw(sp);

    if (active_figure_) {
        active_figure_->Draw(texture);
    }
}

void Layer::AddFigure(Figure *figure) {
    active_figure_.reset(figure);
    active_figure_->SetDedicated(true);
}

void Layer::ResetActiveFigure() {
    active_figure_->SetDedicated(false);
    active_figure_->Draw(texture_);
    texture_.display();
    DeleteActiveFigure();
}

Figure *Layer::GetActiveFigure() {
    if (!active_figure_) return nullptr;
    return active_figure_.get();
}

void Layer::DeleteActiveFigure() {
    if (!active_figure_) return;
    active_figure_.reset();
    assert(!active_figure_);
}

Color Layer::GetPixel(size_t x, size_t y) const {
    auto image = texture_.getTexture().copyToImage();
    return image.getPixel(x, y);
}

void Layer::SetPixel(size_t x, size_t y, Color color) {
    auto image = texture_.getTexture().copyToImage();
    image.setPixel(x, y, color);
    assert(0);
}

void Layer::UpdateFromImage(sf::Image &image) {
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sp(texture);
    texture_.draw(sp);
}
