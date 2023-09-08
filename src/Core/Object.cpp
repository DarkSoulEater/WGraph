#include "Object.h"

// Init static ptr to list of all Object objs
Object* Object::Head_ = nullptr;

Object::Object() : next_(Head_), prev_(nullptr) {
    Head_ = this;
}

Object::~Object() {
    if (prev_) prev_->next_ = next_;
    if (next_) next_->prev_ = prev_;
}