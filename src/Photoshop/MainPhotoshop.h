#ifndef ___MAINPHOTOSHOP_H___
#define ___MAINPHOTOSHOP_H___

#include "Core/Window.h"
#include "UI/WidgetsHandler.h"
#include "UI/PushButton.h"
#include "Photoshop/UI/Clock.h"
#include "Photoshop/UI/CanvasView.h"
#include "Photoshop/UI/Palette.h"

#include "Core/Action/AcDebug.h"
#include "Photoshop/Action/ActCloseWindow.h"
#include "Photoshop/UI/CanvasView.h"

#include "Photoshop/UI/FilterPaletteView.h"

int MainPhotoshop() {
    Vector2 window_size(1200, 800);
    Window window(window_size.X, window_size.Y);

    WidgetsHandler handler(&window);
    auto b1 = static_cast<PushButton*>(handler.AddWidget(new PushButton()).get());
    b1->SetBoundsSize(Vector2(30, 30));
    b1->SetAction(new ActCloseWindow(window));
    b1->SetPosition({200, 100});

    auto pallete = static_cast<Palette*>(handler.AddWidget(new Palette(window)).get());
    auto filter_palette = static_cast<FilterPaletteView*>(handler.AddWidget(new FilterPaletteView).get());

    // handler.AddWidget(new Canvas(pallete->GetToolPalette(), Vector2(300, 300), Vector2(700, 300)));
    // handler.AddWidget(new Canvas(pallete->GetToolPalette(), Vector2(400, 400), Vector2(400, 300)));
    handler.AddWidget(new CanvasView(pallete->GetToolPalette(), filter_palette->GetFilterPalette(), Vector2(600, 600), Vector2(200, 100)));

    // handler.AddWidget(new Clock);

    window.Run();
    
    return 0;
}

#endif // ___MAINPHOTOSHOP_H___