//#include "cmdline_parser.hpp"
#include "Core/Window.h"
#include "CoordsSys.h"
#include "Math/Vector2.h"
#include "Arrow.h"

int main(int argc, char *argv[]) {
    //ParseArgs(argc, argv);

    Window main_window(1100, 1100);

    CoordsSys sys(400, 400);
    sys.SetBackgroundColor(sf::Color::White);
    sys.SetPosition(100, 100);
    sys.Move({10, 10});

    CoordsSys sys2(100, 100);
    sys2.SetBackgroundColor(sf::Color::White);
    sys2.SetPosition(700, 100);
    sys2.SetSize(300, 300);
    sys2.Move({15, 20});
    sys2.Zoom(0.5f);

    CoordsSys sys3(300, 300);
    sys3.SetBackgroundColor(sf::Color::Magenta);
    sys3.SetPosition(100, 600);
    sys3.Move({15, 20});
    sys3.Zoom(0.5f);
    sys3.SetDrawGrid(false);

    const int cnt_arrows = 5;
    Arrow* arrows[cnt_arrows];
    
    const int kRange = 20;
    for (uint32_t i = 0; i < cnt_arrows; ++i) {
        Vector2 begin(rand() % kRange - kRange / 2, rand() % kRange - kRange / 2);
        Vector2 end(rand() % kRange - kRange / 2, rand() % kRange - kRange / 2);
        arrows[i] = new Arrow(begin, end);

        sf::Color color(rand() % 255, rand() % 255, rand() % 255);
        arrows[i]->SetColor(color);
    }

    main_window.Run();

    for (uint32_t i = 0; i < cnt_arrows; ++i) {
        delete arrows[i];
    }

    return 0;
}

// RVO - NRVO -> Copy Elision
// CatmulRom