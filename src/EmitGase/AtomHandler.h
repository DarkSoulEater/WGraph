#ifndef ___ATOMSHANDLER_H___
#define ___ATOMSHANDLER_H___

#include "UI/WidgetsHandler.h"
#include "EmitGase/SimpleAtom.h"
#include "EmitGase/DifficultAtom.h"

class AtomsHandler : WidgetsHandler {
public:
    friend class AtomBox;

    AtomsHandler(Object* parent = nullptr) : WidgetsHandler(parent) {}

private:
    void CollisionChecking();

    void CollisionSS(SimpleAtom* atom0, SimpleAtom* atom1);
    void CollisionDD(DifficultAtom* atom0, DifficultAtom* atom1);

    const float kSimpleThresholdSpeed_ = 400;
    const float kDifficultThresholdSpeed_ = 400;
    const float kMixedThresholdSpeed_ = 400;
};

#endif // ___ATOMSHANDLER_H___