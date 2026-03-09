cmake_minimum_required(VERSION 3.10)
project(mcpe_linux)

set(CMAKE_CXX_STANDARD 11)

# 源文件收集
file(GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/../src/*.cpp"
    "${CMAKE_SOURCE_DIR}/../src/*.c"
)


# 头文件目录，参考win32工程，递归包含所有相关子目录
set(SRC_DIR "${CMAKE_SOURCE_DIR}/../src")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/../lib")
include_directories(
    "${SRC_DIR}"
    "${LIB_DIR}/include"
    "${SRC_DIR}/client"
    "${SRC_DIR}/client/gamemode"
    "${SRC_DIR}/client/gui"
    "${SRC_DIR}/client/gui/components"
    "${SRC_DIR}/client/gui/screens"
    "${SRC_DIR}/client/gui/screens/crafting"
    "${SRC_DIR}/client/gui/screens/touch"
    "${SRC_DIR}/client/model"
    "${SRC_DIR}/client/model/geom"
    "${SRC_DIR}/client/particle"
    "${SRC_DIR}/client/player"
    "${SRC_DIR}/client/player/input"
    "${SRC_DIR}/client/player/input/touchscreen"
    "${SRC_DIR}/client/renderer"
    "${SRC_DIR}/client/renderer/entity"
    "${SRC_DIR}/client/renderer/ptexture"
    "${SRC_DIR}/client/renderer/tileentity"
    "${SRC_DIR}/locale"
    "${SRC_DIR}/nbt"
    "${SRC_DIR}/network"
    "${SRC_DIR}/platform"
    "${SRC_DIR}/platform/input"
    "${SRC_DIR}/raknet"
    "${SRC_DIR}/server"
    "${SRC_DIR}/util"
    "${SRC_DIR}/world"
    "${SRC_DIR}/world/entity"
    "${SRC_DIR}/world/entity/ai/control"
    "${SRC_DIR}/world/entity/animal"
    "${SRC_DIR}/world/entity/item"
    "${SRC_DIR}/world/entity/monster"
    "${SRC_DIR}/world/entity/player"
    "${SRC_DIR}/world/entity/projectile"
    "${SRC_DIR}/world/food"
    "${SRC_DIR}/world/inventory"
    "${SRC_DIR}/world/item"
    "${SRC_DIR}/world/item/crafting"
    "${SRC_DIR}/world/level"
    "${SRC_DIR}/world/level/biome"
    "${SRC_DIR}/world/level/chunk"
    "${SRC_DIR}/world/level/dimension"
    "${SRC_DIR}/world/level/levelgen"
    "${SRC_DIR}/world/level/levelgen/feature"
    "${SRC_DIR}/world/level/levelgen/synth"
    "${SRC_DIR}/world/level/material"
    "${SRC_DIR}/world/level/pathfinder"
    "${SRC_DIR}/world/level/storage"
    "${SRC_DIR}/world/level/tile"
    "${SRC_DIR}/world/level/tile/entity"
    "${SRC_DIR}/world/phys"
)

# Linux专用平台适配
set(PLATFORM_SRC "${CMAKE_SOURCE_DIR}/../../src/AppPlatform_linux.cpp")

add_executable(mcpe_linux ${SRC_FILES} ${PLATFORM_SRC})

# 链接依赖库（如OpenGL、zlib、png等）
target_link_libraries(mcpe_linux
    pthread
    dl
    m
    GL
    X11
    z
    png
)

# 可根据需要添加SDL2等库
# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})
# target_link_libraries(mcpe_linux ${SDL2_LIBRARIES})
