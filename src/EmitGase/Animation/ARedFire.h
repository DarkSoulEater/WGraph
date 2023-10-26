#ifndef ___AREDFIRE_H___
#define ___AREDFIRE_H___

#include "EmitGase/Animation/AFire.h"

class ARedFire : public AFire {
public:
    ARedFire(const Vector2& pivot);

    bool UpdateFrame() override;
};

#endif // ___AREDFIRE_H___