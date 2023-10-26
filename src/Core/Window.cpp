#include "Window.h"
#include <chrono>
#include "Core/Event/MouseEvent.h"
#include "Core/Event/KeyEvent.h"
#include "Core/Event/DrawEvent.h"
#include "Core/Event/UpdateEvent.h"

Window::Window() : window_() { }

Window::Window(uint32_t width, uint32_t height) : window_(sf::VideoMode(width, height), "") {} // TODO: create std::string_view name

inline bool Window::IsOpen() {
    return window_.isOpen();
}

void Window::Run() {
    while (IsOpen()) {
        PollEvent();
        Update();

        Clear();
        Draw();
        Display();
    }
}

void Window::Close() {
    window_.close();
}

inline void Window::Clear() {
    sf::Color background_color(13, 0, 43);
    window_.clear(background_color); // TODO: add color var
}

void Window::Draw() {
    static auto time{std::chrono::steady_clock::now()};
    auto now_time{std::chrono::steady_clock::now()};

    DrawEvent event(window_);
    event.DrawDeltaTime = std::chrono::duration<float>(now_time - time).count();
    time = now_time;
    
    OnEvent(&event);
}

void Window::Update() {
    static auto time{std::chrono::steady_clock::now()};
    auto now_time{std::chrono::steady_clock::now()};
    
    UpdateEvent event;
    event.DeltaTime = std::chrono::duration<float>(now_time - time).count();
    time = now_time;

    OnEvent(&event);
}

void Window::Display() {
    window_.display();
}

void Window::PollEvent() {
    static sf::Vector2i old_mouse_position = sf::Mouse::getPosition(window_);
    bool push_mouse_event = false;
    MouseEvent mouse_event;
    mouse_event.MousePosition = mouse_event.MouseOldPosition = old_mouse_position;

    bool push_key_event = false;
    KeyEvent key_event;

    sf::Event event;
    while (window_.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window_.close();
            } break;

            // Mouse
            case sf::Event::MouseMoved: {
                push_mouse_event = true;

                mouse_event.MousePosition = sf::Mouse::getPosition(window_);
                mouse_event.DeltaMouse = mouse_event.MousePosition - old_mouse_position;

                old_mouse_position = mouse_event.MousePosition;
            } break;

            case sf::Event::MouseButtonPressed: {
                push_mouse_event = true;
                if (event.mouseButton.button == sf::Mouse::Left)   mouse_event.MouseButton[MouseButtom::kLeft].Pressed = true;
                if (event.mouseButton.button == sf::Mouse::Right)  mouse_event.MouseButton[MouseButtom::kRight].Pressed = true;
                if (event.mouseButton.button == sf::Mouse::Middle) mouse_event.MouseButton[MouseButtom::kMiddle].Pressed = true;
            } break;

            case sf::Event::MouseButtonReleased: {
                push_mouse_event = true;
                if (event.mouseButton.button == sf::Mouse::Left)   mouse_event.MouseButton[MouseButtom::kLeft].Released = true;
                if (event.mouseButton.button == sf::Mouse::Right)  mouse_event.MouseButton[MouseButtom::kRight].Released = true;
                if (event.mouseButton.button == sf::Mouse::Middle) mouse_event.MouseButton[MouseButtom::kMiddle].Released = true;
            } break;

            case sf::Event::MouseWheelScrolled: {
                push_mouse_event = true;
                mouse_event.DeltaWheelScroll = event.mouseWheel.delta;
            }

            // Keyboard
            case sf::Event::KeyPressed: {
                push_key_event = true;
                key_event.Keys[event.key.code].Pressed = true;

                // TODO: Set mouse control
            } break;

            case sf::Event::KeyReleased: {
                push_key_event = true;
                key_event.Keys[event.key.code].Released = true;
            } break;

            // Joystick
        };
    }

    if (push_mouse_event) OnEvent(&mouse_event);
    if (push_key_event) OnEvent(&key_event);
}

// void Window::DrawAllObject() {
//     Object* head = Object::Head_;

//     while (head != nullptr) {
//         head->Draw(window_);
//         head = head->next_;
//     }
// }

// void Window::UpdateAllObject() {
//     Object* head = Object::Head_;

//     while (head != nullptr) {
//         head->Update();
//         head = head->next_;
//     }
// }
