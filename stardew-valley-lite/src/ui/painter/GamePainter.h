//
// Created by listerily on 2021/7/6.
//

#ifndef STARDEW_VALLEY_LITE_GAMEPAINTER_H
#define STARDEW_VALLEY_LITE_GAMEPAINTER_H

class GameWorld;
class QWidget;
class GamePainter
{
private:
    const GameWorld& gameWorld;
public:
    GamePainter(const GameWorld& world);

public:
    void paint(QWidget& widget, int width, int height) const;
};


#endif //STARDEW_VALLEY_LITE_GAMEPAINTER_H
