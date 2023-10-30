#ifndef ___BLACKWHITEFILTER_H___
#define ___BLACKWHITEFILTER_H___

#include "Photoshop/Filter/Filter.h"

class BlackWhiteFilter : public Filter {
public:
    BlackWhiteFilter() {}

    virtual void ApplyFilter(Canvas& canvas, const FilterMask& mask) {
        sf::Image image = canvas.GetLayer().GetImage();
        auto size = image.getSize();
        for (size_t y = 0; y < size.y; ++y) {
            for (size_t x = 0; x < size.x; ++x) {
                if (mask.GetPixel(x, y)) {
                    Color color = image.getPixel(x, y);
                    int col = (color.r + color.g + color.b) / 3;
                    image.setPixel(x, y, Color(col, col, col));
                }
            }
        }

        canvas.GetLayer().UpdateFromImage(image);
    }
};

#endif // ___BLACKWHITEFILTER_H___