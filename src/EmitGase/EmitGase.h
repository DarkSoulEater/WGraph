#ifndef ___EMITGASE_H___
#define ___EMITGASE_H___

#include "config.h"

#ifdef EMIT_GASE
#include "Core/Window.h"
#include "Core/Action/ActSendEvent.h"
#include "UI/WidgetsHandler.h"
#include "EmitGase/Panel.h"
#include "EmitGase/AtomBox.h"
#include "EmitGase/PressedButtom.h"
#include "EmitGase/Animation/ABlueFire.h"
#include "EmitGase/Animation/ARedFire.h"
#include "EmitGase/Bar.h"

static int EmitGase() {
    srand(time(0));

    Window window(1043, 630);
    WidgetsHandler emulator(&window);


    // Atom Box
    Vector2 box_positon(500.f, 10.f);
    Vector2 box_size(400.f, 600.f);
    auto atom_box = emulator.AddWidget(new AtomBox(box_positon, box_size));

    // Produce Button
    Vector2 button_shift(30.f);
    Vector2 button_position = box_positon + box_size + button_shift;
    button_position.Y /= 2;
    //button_position = {0, 0};

    auto bProduceSimpleAtom = (PressedButtom*) emulator.AddWidget(
        new PressedButtom(
            new ActSendEvent(new ProduceEvent(AtomType::Simple), atom_box.get())
        )
    ).get();
    bProduceSimpleAtom->SetPosition(button_position);
    bProduceSimpleAtom->SetAnimation(new ARedFire(bProduceSimpleAtom->GetOrigin()));

    auto bProduceDifficultAtom = (PressedButtom*) emulator.AddWidget(
        new PressedButtom(
            new ActSendEvent(new ProduceEvent(AtomType::Difficult), atom_box.get())
        )
    ).get();
    bProduceDifficultAtom->SetPosition(button_position + Vector2(0, 70));
    bProduceDifficultAtom->SetAnimation(new ABlueFire(bProduceDifficultAtom->GetOrigin()));

    // Temp bar
    Vector2 bar_shift(-30.f, 30.f);
    Vector2 bar_position = box_positon + bar_shift;
    emulator.AddWidget(new Bar(
        bar_position, 
        {20, 600}, 
        60, 
        new ActSendEvent(new Event(), atom_box.get())
    ));

    // Background
    emulator.AddWidget(new Panel());

    window.Run();
    return 0;
}

#endif // EMIT_GASE

#endif // ___EMITGASE_H___