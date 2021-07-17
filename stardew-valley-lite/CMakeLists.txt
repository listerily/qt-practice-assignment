cmake_minimum_required(VERSION 3.9)

project(stardew-valley-lite VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Multimedia REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp src/ui/gamestartwindow.ui src/ui/gamestartwindow.h src/ui/gamestartwindow.cpp src/ui/gameplaywindow.ui src/ui/gameplaywindow.h src/ui/gameplaywindow.cpp src/game/GameClient.cpp src/game/GameClient.h src/game/world/GameWorld.cpp src/game/world/GameWorld.h src/game/world/Scene.cpp src/game/world/Scene.h src/game/entity/Entity.cpp src/game/entity/Entity.h src/game/entity/Player.cpp src/game/entity/Player.h src/game/entity/Animal.cpp src/game/entity/Animal.h src/ui/painter/WorldPainter.cpp src/ui/painter/WorldPainter.h src/game/object/TileObject.cpp src/game/object/TileObject.h src/game/config/ConfigLoader.cpp src/game/config/ConfigLoader.h res/textures.qrc res/text.qrc res/audio.qrc src/game/object/impl/GrassLand.cpp src/game/object/impl/GrassLand.h src/game/object/Tile.cpp src/game/object/Tile.h src/game/config/SceneMapConfig.cpp src/game/config/SceneMapConfig.h
        src/game/object/factory/TileObjectFactory.cpp src/game/object/factory/TileObjectFactory.h src/game/world/TileSheet.cpp src/game/world/TileSheet.h src/game/object/TileRef.cpp src/game/object/TileRef.h src/game/object/impl/OakTreeObject.cpp src/game/object/impl/OakTreeObject.h src/game/object/impl/LargeShrub.cpp src/game/object/impl/LargeShrub.h src/game/object/impl/SmallShrub.cpp src/game/object/impl/SmallShrub.h src/game/object/impl/WaterObject.cpp src/game/object/impl/WaterObject.h src/game/object/impl/SmallStone.cpp src/game/object/impl/SmallStone.h src/game/object/impl/ManyStones.cpp src/game/object/impl/ManyStones.h src/game/object/impl/PinkFlower.cpp src/game/object/impl/PinkFlower.h src/game/object/impl/BlueFlower.cpp src/game/object/impl/BlueFlower.h src/game/world/PlayerController.cpp src/game/world/PlayerController.h src/game/inventory/Inventory.cpp src/game/inventory/Inventory.h src/game/object/impl/FruitsBarrel.cpp src/game/object/impl/FruitsBarrel.h src/game/object/impl/LilyPad.cpp src/game/object/impl/LilyPad.h src/game/object/impl/WaterStakes.cpp src/game/object/impl/WaterStakes.h src/game/object/impl/FloatingPlant.cpp src/game/object/impl/FloatingPlant.h src/game/object/impl/FlowerPot.cpp src/game/object/impl/FlowerPot.h src/game/inventory/ItemInstance.cpp src/game/inventory/ItemInstance.h src/game/item/Item.cpp src/game/item/Item.h src/game/item/impl/WoodItem.cpp src/game/item/impl/WoodItem.h src/game/item/ItemManager.cpp src/game/item/ItemManager.h src/game/item/impl/WeedsItem.cpp src/game/item/impl/WeedsItem.h src/game/item/impl/StoneItem.cpp src/game/item/impl/StoneItem.h src/game/object/impl/BranchObject.cpp src/game/object/impl/BranchObject.h src/game/object/impl/StoneObject.cpp src/game/object/impl/StoneObject.h src/game/object/impl/WeedsObject.cpp src/game/object/impl/WeedsObject.h src/game/InputHandler.cpp src/game/InputHandler.h src/game/object/impl/PineTreeObject.cpp src/game/object/impl/PineTreeObject.h src/game/object/impl/GrassFlowerObject.cpp src/game/object/impl/GrassFlowerObject.h src/game/object/impl/WaterBankObject.cpp src/game/object/impl/WaterBankObject.h src/game/object/impl/FenceObject.cpp src/game/object/impl/FenceObject.h src/game/object/impl/TentObject.cpp src/game/object/impl/TentObject.h src/game/object/impl/HouseObject.cpp src/game/object/impl/HouseObject.h src/game/object/impl/TrestleObject.cpp src/game/object/impl/TrestleObject.h src/game/object/impl/BorderObject.cpp src/game/object/impl/BorderObject.h src/game/object/impl/AppleTreeObject.cpp src/game/object/impl/AppleTreeObject.h src/game/object/impl/MailBoxObject.cpp src/game/object/impl/MailBoxObject.h src/game/object/impl/WoodenPlate.cpp src/game/object/impl/WoodenPlate.h src/game/object/impl/StonePathObject.cpp src/game/object/impl/StonePathObject.h src/game/object/impl/AutoMobileObject.cpp src/game/object/impl/AutoMobileObject.h src/game/object/impl/LargeWoodObject.cpp src/game/object/impl/LargeWoodObject.h src/game/object/impl/HouseBackgroundObject.cpp src/game/object/impl/HouseBackgroundObject.h src/game/object/impl/BedObject.cpp src/game/object/impl/BedObject.h src/game/object/impl/TVObject.cpp src/game/object/impl/TVObject.h src/game/object/impl/HomeStairsObject.cpp src/game/object/impl/HomeStairsObject.h src/game/object/impl/HomeBorderObject.cpp src/game/object/impl/HomeBorderObject.h src/game/item/impl/StrawberryItem.cpp src/game/item/impl/StrawberryItem.h src/game/world/WorldStatus.cpp src/game/world/WorldStatus.h src/game/world/WorldEvent.cpp src/game/world/WorldEvent.h src/game/action/Action.cpp src/game/action/Action.h src/game/action/PickupAction.cpp src/game/action/PickupAction.h src/game/action/SwitchSceneAction.cpp src/game/action/SwitchSceneAction.h src/game/item/impl/AxeItem.cpp src/game/item/impl/AxeItem.h src/game/action/SmashAction.cpp src/game/action/SmashAction.h src/game/object/impl/TreeObject.cpp src/game/object/impl/TreeObject.h src/game/item/impl/PickaxeItem.cpp src/game/item/impl/PickaxeItem.h src/game/item/impl/HoeItem.cpp src/game/item/impl/HoeItem.h src/game/item/impl/MixedSeedsItem.cpp src/game/item/impl/MixedSeedsItem.h src/game/action/SmashAndGetAction.cpp src/game/action/SmashAndGetAction.h src/game/object/impl/HoeSoilObject.cpp src/game/object/impl/HoeSoilObject.h src/game/action/SmashAndCreateSoilAction.cpp src/game/action/SmashAndCreateSoilAction.h src/game/item/impl/ParsnipItem.cpp src/game/item/impl/ParsnipItem.h src/game/object/impl/ParsnipObject.cpp src/game/object/impl/ParsnipObject.h)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(stardew-valley-lite
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(stardew-valley-lite SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(stardew-valley-lite
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(stardew-valley-lite PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia pthread)

set_target_properties(stardew-valley-lite PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(stardew-valley-lite)
endif()
