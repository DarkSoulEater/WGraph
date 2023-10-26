#ifndef ___WIDGETSHANDLER_H___
#define ___WIDGETSHANDLER_H___

#include <memory>
#include "Core/Window.h"
#include "UI/Widget.h"

#include <iostream> // TODO: delete

class WidgetsHandler : public Object {
public:
    WidgetsHandler(Object* parent = nullptr) : Object(parent) {}
    virtual ~WidgetsHandler();

    virtual void OnEvent(const Event* event) override;

    std::shared_ptr<Widget> AddWidget(Widget* widget);

protected:
    struct Node {
        Node(Widget* widget) : pWidget(widget) {}

        std::shared_ptr<Widget> pWidget;
        Node* Next = nullptr;
        Node* Prev = nullptr;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    using DArray = std::vector<std::shared_ptr<Widget>>;
    DArray widgets_;

protected:
    virtual void OnMouseEvent(const MouseEvent& event);
    virtual void OnDrawEvent(const DrawEvent& event);
};

#endif // ___WIDGETSHANDLER_H___