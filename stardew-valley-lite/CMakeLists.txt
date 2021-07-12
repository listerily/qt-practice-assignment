cmake_minimum_required(VERSION 3.5)

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

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp src/ui/gameplaywindow.ui src/ui/gameplaywindow.h src/ui/gameplaywindow.cpp src/game/GameClient.cpp src/game/GameClient.h src/game/world/GameWorld.cpp src/game/world/GameWorld.h src/game/world/GameDimension.cpp src/game/world/GameDimension.h src/game/entity/Entity.cpp src/game/entity/Entity.h src/game/entity/Player.cpp src/game/entity/Player.h src/game/entity/Animal.cpp src/game/entity/Animal.h src/ui/painter/GamePainter.cpp src/ui/painter/GamePainter.h src/game/world/object/TileObject.cpp src/game/world/object/TileObject.h src/game/event/EventBus.cpp src/game/event/EventBus.h src/config/ConfigLoader.cpp src/config/ConfigLoader.h res/textures.qrc res/text.qrc src/game/world/object/impl/GrassLand.cpp src/game/world/object/impl/GrassLand.h src/game/world/object/Tile.cpp src/game/world/object/Tile.h src/config/DimMapConfig.cpp src/config/DimMapConfig.h
        src/game/world/object/impl/PathLand.cpp src/game/world/object/impl/PathLand.h src/game/world/object/factory/TileObjectFactory.cpp src/game/world/object/factory/TileObjectFactory.h src/game/world/TileSheet.cpp src/game/world/TileSheet.h src/game/world/object/TileRef.cpp src/game/world/object/TileRef.h src/game/world/object/impl/OakTreeObject.cpp src/game/world/object/impl/OakTreeObject.h src/game/world/object/impl/LargeShrub.cpp src/game/world/object/impl/LargeShrub.h src/game/world/object/impl/SmallShrub.cpp src/game/world/object/impl/SmallShrub.h src/game/world/object/impl/WaterObject.cpp src/game/world/object/impl/WaterObject.h src/game/world/object/impl/PloughedLand.cpp src/game/world/object/impl/PloughedLand.h src/game/world/object/impl/SmallStone.cpp src/game/world/object/impl/SmallStone.h src/game/world/object/impl/ManyStones.cpp src/game/world/object/impl/ManyStones.h src/game/world/object/impl/PinkFlower.cpp src/game/world/object/impl/PinkFlower.h src/game/world/object/impl/BlueFlower.cpp src/game/world/object/impl/BlueFlower.h src/game/world/PlayerController.cpp src/game/world/PlayerController.h)

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

target_link_libraries(stardew-valley-lite PRIVATE Qt${QT_VERSION_MAJOR}::Widgets pthread)

set_target_properties(stardew-valley-lite PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(stardew-valley-lite)
endif()
