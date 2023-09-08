#include "Window.h"

Window::Window() : window_() { }

Window::Window(uint32_t width, uint32_t height) : window_(sf::VideoMode(width, height), "") {} // TODO: create std::string_view name

inline bool Window::IsOpen() {
    return window_.isOpen();
}

void Window::Run() {
    while (IsOpen()) {
        PollEvent();
        UpdateAllObject();

        Clear();
        DrawAllObject();
        Display();
    }
}

inline void Window::Clear() {
    window_.clear(sf::Color::Black); // TODO: add color var
}

void Window::Display() {
    window_.display();
}

void Window::PollEvent() {
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) { // TODO: add switch
            window_.close();
        }
    }
}

void Window::DrawAllObject() {
    Object* head = Object::Head_;

    while (head != nullptr) {
        head->Draw(window_);
        head = head->next_;
    }
}

void Window::UpdateAllObject() {
    Object* head = Object::Head_;

    while (head != nullptr) {
        head->Update();
        head = head->next_;
    }
}
