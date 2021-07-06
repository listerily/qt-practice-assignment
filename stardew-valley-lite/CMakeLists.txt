cmake_minimum_required(VERSION 3.20)
project(stardew_valley_lite)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_ATOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME} src/main.cpp src/ui/gameplaywindow.h src/ui/gameplaywindow.cpp src/game/GameClient.cpp src/game/GameClient.h src/game/world/GameWorld.cpp src/game/world/GameWorld.h src/game/world/GameDimension.cpp src/game/world/GameDimension.h src/game/ResourceLoader.cpp src/game/ResourceLoader.h src/game/entity/Entity.cpp src/game/entity/Entity.h src/game/entity/Player.cpp src/game/entity/Player.h src/game/entity/Animal.cpp src/game/entity/Animal.h src/game/world/TileSheet.cpp src/game/world/TileSheet.h src/game/world/tile/Tile.cpp src/game/world/tile/Tile.h src/ui/painter/GamePainter.cpp src/ui/painter/GamePainter.h src/game/world/object/StaticObject.cpp src/game/world/object/StaticObject.h src/game/event/EventBus.cpp src/game/event/EventBus.h src/config/ConfigLoader.cpp src/config/ConfigLoader.h res/textures.qrc res/text.qrc src/config/StaticObjectConfig.cpp src/config/StaticObjectConfig.h src/game/world/object/impl/GrassLand.cpp src/game/world/object/impl/GrassLand.h src/game/world/object/ObjectTile.cpp src/game/world/object/ObjectTile.h src/config/DimMapConfig.cpp src/config/DimMapConfig.h)

set(CMAKE_PREFIX_PATH "/usr/lib/cmake/Qt5")
if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} pthread)
