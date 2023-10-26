#include "WidgetsHandler.h"
#include <assert.h>

WidgetsHandler::~WidgetsHandler() {
    while (head_ != nullptr) {
        Node* next = head_->Next;
        delete head_;
        head_ = next;
    }
}

void WidgetsHandler::OnEvent(const Event *event) {
    if (event->Type() == EventType::Mouse) {
        OnMouseEvent(*static_cast<const MouseEvent*>(event));
        return;
    } else if (event->Type() == EventType::Draw) {
        OnDrawEvent(*static_cast<const DrawEvent*>(event));
        return;
    }

    Object::OnEvent(event);
}

std::shared_ptr<Widget> WidgetsHandler::AddWidget(Widget *widget) {
    assert(widget);
    widget->SetParent(this);
    Node* node = new Node(widget);
    if (head_ == nullptr) {
        head_ = tail_ = node;
    } else {
        node->Prev = tail_;
        tail_->Next = node;
        tail_ = node;
    }
    
    return node->pWidget;
}

void WidgetsHandler::OnMouseEvent(const MouseEvent &event) {
    if (head_ == nullptr) return;

    bool pressed_event = false;
    for (int i = 0; i < event.kMouseButtonCount; ++i) {
        pressed_event |= event.MouseButton[i].Pressed;
    }

    if (!pressed_event) {
        Object::OnEvent(&event);
        return;
    }

    Node* node = head_;
    Node* prev = nullptr;

    if (head_ == tail_) goto PushEventHead;

    while (node != nullptr) {
        if (node->pWidget->GetGlobalBounds().Contains(event.MousePosition)) {
            if (node == head_) goto PushEventHead;
            if (node == tail_) {
                tail_->Prev->Next = nullptr;
                tail_ = tail_->Prev;
            }
            else {
                node->Prev->Next = node->Next;
                node->Next->Prev = node->Prev;
            }

            node->Next = head_;
            node->Prev = nullptr;
            head_->Prev = node;
            head_ = node;
            node->pWidget->OnEvent(&event);
            return;
        }
        prev = node;
        node = node->Next;
    }

    PushEventHead: {
        if (head_) head_->pWidget->OnEvent(&event);
    }
}

void WidgetsHandler::OnDrawEvent(const DrawEvent &event) {
    Node* node = tail_;
    while (node != nullptr) {
        node->pWidget->OnEvent(&event);
        node = node->Prev;
    }
}
