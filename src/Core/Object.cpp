#include <assert.h>
#include "Core/Object.h"
#include "Object.h"

Object::Object(Object *parent) : parent_(parent) {
    static uint64_t pullID = 1;
    id_ = pullID++;

    SetParent(parent);
}

Object::~Object() {
    // for (auto child : childs_) {
    //     delete child;
    // }
}

void Object::SetParent(Object *parent) {
    if (parent_ != nullptr) {
        parent_->childs_.erase(this);
    }

    parent_ = parent;

    if (parent_) {
        parent_->childs_.insert(this);
    }
}

// Object *Object::GetParent() const {
//     return parent_;
// }

Vector2 Object::MapToParent(const Vector2 &point) const {
    if (parent_ == nullptr) return point;
    return point + parent_->position_;
}

Vector2 Object::MapToGlobal(const Vector2 &point) const {
    if (parent_ == nullptr) {
        //std::cout << "IS Gloabl point " << point.X << " " << point.Y << "\n";
        return point;
    }
    //auto u = parent_->MapToGlobal(position_);
    //std::cout << "MapToGlobal = " << 
    return parent_->MapToGlobal(point) + position_;
}

Vector2 Object::MapFromGlobal(const Vector2 &point) const {
    //assert(0 && "not implemented");
    if (parent_ == nullptr) {
        return point - position_;
    }
    return parent_->MapFromGlobal(point) - position_;
}

void Object::OnEvent(const Event *event) {
    if (!is_enabled) return;
    for (auto& child : childs_) {
        child->OnEvent(event);
    }
}
