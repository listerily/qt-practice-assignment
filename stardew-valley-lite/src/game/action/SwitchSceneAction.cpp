//
// Created by listerily on 2021/7/16.
//

#include "SwitchSceneAction.h"

SwitchSceneAction::SwitchSceneAction(std::string sceneID) : id(std::move(sceneID))
{

}

int SwitchSceneAction::getDuration() const
{
    return Action::getDuration();
}

void SwitchSceneAction::onActionEnd(GameWorld &w, Scene &s, Player &p)
{
    Action::onActionEnd(w, s, p);
}
