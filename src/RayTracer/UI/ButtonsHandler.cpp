#include "ButtonsHandler.h"

ButtonsHandler::ButtonsHandler(Window &window) {
    
}

std::shared_ptr<Button> ButtonsHandler::AddButton(std::shared_ptr<Button> button)
{
    buttons.push_back(button);
    return button;
}