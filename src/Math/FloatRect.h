#ifndef ___FLOATRECT_H___
#define ___FLOATRECT_H___

#include "Math/Vector2.h"

class FloatRect {
public:
    FloatRect(const Vector2& position, const Vector2& size) : position_(position), size_(size) {}
    FloatRect(float x, float y, float size_x, float size_y) : position_(x, y), size_(size_x, size_y) {}

    void SetPosition(const Vector2& position) { position_ = position; }
    Vector2 GetPosition() const { return position_; }

    void SetSize(const Vector2& size) { size_ = size; }
    Vector2 GetSize() const { return size_; }

    void Move(const Vector2& vec) { position_ += vec; }

    bool Contains(float x, float y);
    bool Contains(const Vector2& point);

    void Dump();

    bool Intersects(const FloatRect& rect);

private:
    Vector2 position_;
    Vector2 size_;
};

#endif // ___FLOATRECT_H___