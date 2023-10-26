#ifndef ___EXPLOSION_H___
#define ___EXPLOSION_H___

#include <memory>
#include "UI/Widget.h"
#include "EmitGase/Animation/Animation.h"

class Explosion : public Widget {
public:
    Explosion();

    virtual void OnDrawEvent(const DrawEvent& event) override;

private:
    std::shared_ptr<Animation> animation_;
};

#endif // ___EXPLOSION_H___