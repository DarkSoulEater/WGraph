#ifndef ___WINDOW_H___
#define ___WINDOW_H___

#include "SFML/Graphics.hpp"
#include "Core/Object.h"

class Window {
public:
    Window();
    Window(uint32_t width, uint32_t height);
    virtual ~Window() = default;

    bool IsOpen();

    void Run();

private:
    void Clear();
    void Display();

    void PollEvent();

private:
    void DrawAllObject();
    void UpdateAllObject();

    sf::RenderWindow window_;
};

#endif // ___WINDOW_H___