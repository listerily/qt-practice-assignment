//
// Created by listerily on 2021/7/16.
//

#include "ParsnipObject.h"

#include "../../action/PickupAction.h"

ParsnipObject::ParsnipObject(int x, int y) : TileObject("parsnip", x, y)
{
    stage = 0;
    updateTiles();
}

void ParsnipObject::afterNight(GameWorld &world, Scene &scene)
{
    TileObject::afterNight(world, scene);
    if (stage < 4)
        ++stage;
    updateTiles();
    scene.updateObject(this);
}

void ParsnipObject::updateTiles()
{
    const std::vector<std::string> textures[2] = {{
                                                          ":/svl/textures/crops/7_1_0.png",
                                                          ":/svl/textures/crops/7_2_0.png",
                                                          ":/svl/textures/crops/7_3_0.png",
                                                          ":/svl/textures/crops/7_4_0.png",
                                                          ":/svl/textures/crops/7_5_0.png",
                                                  },
                                                  {
                                                          ":/svl/textures/crops/7_1_1.png",
                                                          ":/svl/textures/crops/7_2_1.png",
                                                          ":/svl/textures/crops/7_3_1.png",
                                                          ":/svl/textures/crops/7_4_1.png",
                                                          ":/svl/textures/crops/7_5_1.png",
                                                  },
    };
    tiles = {
            {{textures[1][stage]}, Tile::WalkableType::ABLE, 0, 0,  Tile::DisplayPriority::ON_GROUND},
            {{textures[0][stage]}, Tile::WalkableType::ABLE, 0, -1, Tile::DisplayPriority::ON_GROUND},
    };
}

std::unique_ptr<Action>
ParsnipObject::interact(GameWorld &world, ItemInstance *instance, Player &player, Scene &scene, int x, int y)
{
    if (stage == 4)
    {
        scene.removeObject(this);
        return std::make_unique<PickupAction>(*ItemInstance("parsnip").getItem());
    }
    return TileObject::interact(world, instance, player, scene, x, y);
}
