#include "cmdline_parser.hpp"
#include "EmitGase/EmitGase.h"
#include "Photoshop/MainPhotoshop.h"

int main(int argc, char *argv[]) {
    //ParseArgs(argc, argv);
    return MainPhotoshop();
    //return EmitGase();
    // Window main_window(1100, 1100);

    // WidgetsHandler hwidgets(main_window);
    // auto widget = hwidgets.AddWidget(new Widget);

    // main_window.Run();

    return 0;
    // Window main_window(1100, 1100);

    // Button b1(main_window);
    // b1.SetPosition(1000, 1000);

    // Button b2(main_window);
    // b2.SetPosition(900, 1000);

    // Camera camera;
    // b1.SetFunction(std::bind(SwitchRotateCamera, camera));
    // b2.SetFunction(std::bind(SwitchRotateLight, camera));
    // //camera.Run();

    // main_window.Run();

    // return 0;

    // CoordsSys sys(400, 400);
    // sys.SetBackgroundColor(sf::Color::White);
    // sys.SetPosition(100, 100);
    // sys.Move({10, 10});

    // CoordsSys sys2(100, 100);
    // sys2.SetBackgroundColor(sf::Color::White);
    // sys2.SetPosition(700, 100);
    // sys2.SetSize(300, 300);
    // sys2.Move({15, 20});
    // sys2.Zoom(0.5f);

    // CoordsSys sys3(300, 300);
    // sys3.SetBackgroundColor(sf::Color::Magenta);
    // sys3.SetPosition(100, 600);
    // sys3.Move({15, 20});
    // sys3.Zoom(0.5f);
    // sys3.SetDrawGrid(false);

    // const int cnt_arrows = 5;
    // Arrow* arrows[cnt_arrows];
    
    // const int kRange = 20;
    // for (uint32_t i = 0; i < cnt_arrows; ++i) {
    //     Vector2 begin(rand() % kRange - kRange / 2, rand() % kRange - kRange / 2);
    //     Vector2 end(rand() % kRange - kRange / 2, rand() % kRange - kRange / 2);
    //     arrows[i] = new Arrow(begin, end);

    //     sf::Color color(rand() % 255, rand() % 255, rand() % 255);
    //     arrows[i]->SetColor(color);
    // }

    // main_window.Run();

    // for (uint32_t i = 0; i < cnt_arrows; ++i) {
    //     delete arrows[i];
    // }

    // return 0;
}

// RVO - NRVO -> Copy Elision
// CatmulRom
// bool vector, interpol vector
// диффузное рассеяное бликовое 
// рельеф чем небольшой рандом координат (normal mapping)

// (-0.000000, 0.000000, 1.000000)
// (-1.000000, 0.000000, -0.000000)
// (1.000000, 0.000000, 0.000000)
// (0.000000, 0.000000, 1.000000)
// (-0.000000, 0.000000, 0.000000)