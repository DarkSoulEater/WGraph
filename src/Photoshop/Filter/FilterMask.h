#ifndef ___FILTERMASK_H___
#define ___FILTERMASK_H___

#include <assert.h>
#include <cstdio>
#include <vector>

class FilterMask {
public:
    FilterMask(size_t width, size_t height);

    size_t GetWidth()  const { return width_;  }
    size_t GetHeight() const { return height_; }

    bool GetPixel(size_t x, size_t y) const { assert(x < width_ && y < height_); return mask_[y][x]; }
    void SetPixel(size_t x, size_t y, bool value) { assert(x < width_ && y < height_); mask_[y][x] = value; }

    void Fill(bool value);
    void Invert();

private:
    size_t width_;
    size_t height_;

    std::vector<std::vector<bool>> mask_;
};

#endif // ___FILTERMASK_H___