#ifndef ___LAYER_H___
#define ___LAYER_H___

#include <assert.h>
#include <memory>
#include "Math/Vector2.h"
#include "Photoshop/Canvas/Figure/Figure.h"
#include "Photoshop/Tool/Color.h"

class Layer {
public:
    Layer() {}
    Layer(Vector2 size);

    bool IsVisible()              { return visible_; }
    void SetVisible(bool visible) { visible_ = visible; }

    void AddFigure(Figure* figure);

    void Draw(sf::RenderTarget& texture);

    void ResetActiveFigure();
    Figure* GetActiveFigure();
    void DeleteActiveFigure();

    Vector2 GetSize() const { return size_; }
    Color GetPixel(size_t x, size_t y) const;
    void SetPixel(size_t x, size_t y, Color color);

    sf::Image GetImage() const { return texture_.getTexture().copyToImage(); }
    void UpdateFromImage(sf::Image& image);

private:
    bool visible_ = true;

private:
    Vector2 size_ = Vector2(0, 0);
    sf::RenderTexture texture_;

private:
    std::shared_ptr<Figure> active_figure_ = nullptr;
};

#endif // ___LAYER_H___