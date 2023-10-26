#ifndef ___AFIRE_H___
#define ___AFIRE_H___

#include "Math/Vector2.h"
#include "EmitGase/Animation/Animation.h"

class AFire : public Animation {
public:
    AFire(const Vector2& pivot);

protected:
    int index_ = 0;
};

#endif // ___AFIRE_H___