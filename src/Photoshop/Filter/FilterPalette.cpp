#include "FilterPalette.h"
#include "Photoshop/Filter/BlackWhiteFilter.h"

FilterPalette::FilterPalette() {
    filters_.push_back(new BlackWhiteFilter());
}

FilterPalette::~FilterPalette() {
    for (size_t i = 0; i < filters_.size(); ++i) {
        delete filters_[i];
    }
}
