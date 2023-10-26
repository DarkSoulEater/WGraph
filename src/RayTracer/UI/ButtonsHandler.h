#ifndef ___BUTTONSHANDLER_H___
#define ___BUTTONSHANDLER_H___

#include <memory>
#include <vector>
#include "Core/Window.h"
#include "Button.h"

class ButtonsHandler {
public:
    ButtonsHandler(Window& window);
    
    std::shared_ptr<Button> AddButton(std::shared_ptr<Button> button);

private:
    using DynamicArray = std::vector<std::shared_ptr<Button>>;
    DynamicArray buttons;
};

#endif // ___BUTTONSHANDLER_H___