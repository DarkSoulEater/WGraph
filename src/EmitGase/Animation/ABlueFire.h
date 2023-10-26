#ifndef ___ABLUEFIRE_H___
#define ___ABLUEFIRE_H___

#include "EmitGase/Animation/AFire.h"

class ABlueFire : public AFire {
public:
    ABlueFire(const Vector2& pivot);

    bool UpdateFrame() override;
};

#endif // ___ABLUEFIRE_H___