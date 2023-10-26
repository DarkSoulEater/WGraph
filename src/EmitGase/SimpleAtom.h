#ifndef ___SIMPLEATOM_H___
#define ___SIMPLEATOM_H___

#include <memory>
#include "EmitGase/Atom.h"
#include "EmitGase/Animation/Animation.h"

class SimpleAtom : public Atom {
public:
    SimpleAtom(Vector2 box_position, Vector2 box_size);

    virtual AtomType Type() override { return AtomType::Simple; }

    virtual void OnDrawEvent(const DrawEvent& event) override;

private:
    std::shared_ptr<Animation> animation_;
};

#endif // ___SIMPLEATOM_H___