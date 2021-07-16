//
// Created by listerily on 2021/7/13.
//

#ifndef STARDEW_VALLEY_LITE_INPUTHANDLER_H
#define STARDEW_VALLEY_LITE_INPUTHANDLER_H

#include <unordered_map>

class InputHandler
{
private:
    std::unordered_map<int, bool> keymap;
public:
    void keyPressEvent(int key);

    void keyReleaseEvent(int key);

    bool isKeyPressed(int) const;
};


#endif //STARDEW_VALLEY_LITE_INPUTHANDLER_H
