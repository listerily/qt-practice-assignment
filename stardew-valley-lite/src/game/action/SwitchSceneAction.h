//
// Created by listerily on 2021/7/16.
//

#ifndef STARDEW_VALLEY_LITE_SWITCHSCENEACTION_H
#define STARDEW_VALLEY_LITE_SWITCHSCENEACTION_H

#include <string>
#include "Action.h"

class SwitchSceneAction : public Action
{
private:
    std::string id;
public:
    explicit SwitchSceneAction(std::string sceneID);

    int getDuration() const override;
    void onActionEnd(GameWorld &w, Scene &s, Player &p) override;
};


#endif //STARDEW_VALLEY_LITE_SWITCHSCENEACTION_H
