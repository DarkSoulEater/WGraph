#ifndef ___AEXPLOSION_H___
#define ___AEXPLOSION_H___

#include "EmitGase/Animation/AFire.h"

class AExplosion : public AFire {
public:
    AExplosion();

    bool UpdateFrame() override;

private:
    /* data */
};

#endif // ___AEXPLOSION_H___