#ifndef ___ACTCLOSEWINDOW_H___
#define ___ACTCLOSEWINDOW_H___

#include "Core/Action/Action.h"
#include "Core/Window.h"

class ActCloseWindow : public Action {
public:
    ActCloseWindow(Window& window) : window_(window) {}
    
    virtual void operator()() { window_.Close(); }

private:
    Window& window_;
};

#endif // ___ACTCLOSEWINDOW_H___