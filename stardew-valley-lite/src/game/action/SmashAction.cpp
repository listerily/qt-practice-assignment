//
// Created by listerily on 2021/7/16.
//

#include "SmashAction.h"

SmashAction::SmashAction(const Item &tool) :
        tool(tool)
{

}

int SmashAction::getDuration() const
{
    return 10;
}

void SmashAction::onActionEnd(GameWorld &w, Scene &s, Player &p)
{
    Action::onActionEnd(w, s, p);
}

const Item &SmashAction::getToolItem() const
{
    return tool;
}
