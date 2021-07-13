//
// Created by listerily on 2021/7/13.
//

#include "InputHandler.h"

void InputHandler::keyPressEvent(int key)
{
    keymap[key] = true;
}

void InputHandler::keyReleaseEvent(int key)
{
    keymap[key] = false;
}

bool InputHandler::isKeyPressed(int key) const
{
    auto const& result = keymap.find(key);
    if(result == keymap.end())
        return false;
    return result->second;
}
