#ifndef ___OBJECT_H___
#define ___OBJECT_H___

#include <vector>
#include <inttypes.h>
#include <unordered_set>
#include "Core/Seeker.h"
#include "Math/Vector2.h"

class Object {
public:
    Object(Object* parent = nullptr);
    virtual ~Object();

    uint64_t Id() const { return id_; }

    void SetEnabled(bool enabled) { is_enabled = enabled; }
    bool IsEnabled() const { return is_enabled; }

    void SetParent(Object* parent);
    Object* GetParent() const { return parent_; }

    void SetPosition(const Vector2& position) { position_ = position; }
    Vector2 GetPosition() const { return position_; }
    void Move(const Vector2& vec) { position_ += vec; }

    Vector2 MapToParent(const Vector2& point) const;
    // Vector2 MapFromParent(const Vector2& point) const;
    Vector2 MapToGlobal(const Vector2& point = {0, 0}) const;
    Vector2 MapFromGlobal(const Vector2& point) const;

    virtual void OnEvent(const Event* event);

private:
    uint64_t id_ = 0;
    Object*  parent_  = nullptr;

protected:
    bool is_enabled = true;
    Vector2 position_ = Vector2(0, 0);

private:
    using Set = std::unordered_set<Object*>;
    Set childs_;
};

#endif // ___OBJECT_H___