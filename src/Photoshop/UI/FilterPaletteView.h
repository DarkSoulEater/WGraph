#ifndef ___FILTERPALETTEVIEW_H___
#define ___FILTERPALETTEVIEW_H___

#include "UI/Widget.h"
#include "Photoshop/Filter/FilterPalette.h"

class FilterPaletteView : public Widget {
public:
    FilterPaletteView() {}

    FilterPalette& GetFilterPalette() { return filter_palette; }
private:
    FilterPalette filter_palette;
};

#endif // ___FILTERPALETTEVIEW_H___