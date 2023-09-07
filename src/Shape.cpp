#include "Shape.h"

// Init static ptr to list of all Shape objs
Shape* Shape::Head_ = nullptr;

Shape::Shape() : next_(Head_), prev_(nullptr) {
    Head_ = this;
}

Shape::~Shape() {
    if (prev_) prev_->next_ = next_;
    if (next_) next_->prev_ = prev_;
}
