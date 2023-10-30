#include "FilterMask.h"

FilterMask::FilterMask(size_t width, size_t height) : width_(width), height_(height) {
    mask_.resize(height_, std::vector<bool>(width_, true));
}

void FilterMask::Fill(bool value) {
    for (size_t y = 0; y < height_; ++y) {
        for (size_t x = 0; x < width_; ++x) {
            mask_[y][x] = value;
        }
    }
}

void FilterMask::Invert() {
    for (size_t y = 0; y < height_; ++y) {
        for (size_t x = 0; x < width_; ++x) {
            mask_[y][x] != mask_[y][x];
        }
    }
}
