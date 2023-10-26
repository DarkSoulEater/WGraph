#ifndef ___WINDOW_H___
#define ___WINDOW_H___

#include "SFML/Graphics.hpp"
#include "Core/Object.h"

class Window : public Object {
public:
    Window();
    Window(uint32_t width, uint32_t height);
    virtual ~Window() {}

    bool IsOpen();

    void Run();
    void Close();

private:
    void Clear();
    void Draw();
    void Update();
    void Display();

    void PollEvent();

private:
    sf::RenderWindow window_;
};

#endif // ___WINDOW_H___