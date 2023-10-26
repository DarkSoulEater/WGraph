#ifndef ___DIFFICULTATOM_H___
#define ___DIFFICULTATOM_H___

#include <memory>
#include "EmitGase/Atom.h"
#include "EmitGase/Animation/Animation.h"

class DifficultAtom : public Atom {
public:
    DifficultAtom(Vector2 box_position, Vector2 box_size);

    virtual AtomType Type() override { return AtomType::Difficult; }

    virtual void OnDrawEvent(const DrawEvent& event) override;

private:
    std::shared_ptr<Animation> animation_;
};

#endif // ___DIFFICULTATOM_H___