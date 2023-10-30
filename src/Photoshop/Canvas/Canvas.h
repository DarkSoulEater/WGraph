#ifndef ___CANVAS_H___
#define ___CANVAS_H___

#include <assert.h>
#include <memory>

#include "Photoshop/Canvas/Figure/Figure.h"
#include "Photoshop/Tool/ToolPalette.h"
#include "Photoshop/Canvas/Layer.h"

class Canvas : public Widget {
public:
    Canvas(ToolPalette& palette, Vector2 canvas_size = Vector2(-1, -1));

    Layer& GetLayer() { return layer1_; }

private:
    Layer layer1_;
    ToolPalette& palette_;

private:
    Vector2 canvas_size_ = {0, 0};

private:
    sf::Image image_;
    sf::RenderTexture texture_;
};

#endif // ___CANVAS_H___