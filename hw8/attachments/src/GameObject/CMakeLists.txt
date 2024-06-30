cmake_minimum_required(VERSION 3.16)
project(PVZ)

# 设置公共头文件路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 公共链接库
set(COMMON_LIBS
  Framework
  GameObject
)

# 定义和链接 GameObject 库
add_library(GameObject STATIC GameObject.cpp)
target_link_libraries(GameObject PUBLIC Framework)

# 定义和链接 Background 库
add_library(Background STATIC Background.cpp)
target_link_libraries(Background PUBLIC GameObject)

# 定义和链接 PlantingSpot 库
add_library(PlantingSpot STATIC PlantingSpot.cpp)
target_link_libraries(PlantingSpot PUBLIC GameObject)

# 定义和链接 SeedButton 库
add_library(SeedButton STATIC SeedButton.cpp)
target_link_libraries(SeedButton PUBLIC GameObject CooldownMask)

# 定义和链接 SunflowerSeed 库
add_library(SunflowerSeed STATIC SunflowerSeed.cpp)
target_link_libraries(SunflowerSeed PUBLIC SeedButton)

# 定义和链接 PeashooterSeed 库
add_library(PeashooterSeed STATIC PeashooterSeed.cpp)
target_link_libraries(PeashooterSeed PUBLIC SeedButton)

# 定义和链接 WallnutSeed 库
add_library(WallnutSeed STATIC WallnutSeed.cpp)
target_link_libraries(WallnutSeed PUBLIC SeedButton)

# 定义和链接 CooldownMask 库
add_library(CooldownMask STATIC CooldownMask.cpp)
target_link_libraries(CooldownMask PUBLIC GameObject)

# 定义和链接 Sun 库
add_library(Sun STATIC Sun.cpp)
target_link_libraries(Sun PUBLIC GameObject)

# 定义和链接 Plant 库
add_library(Plant STATIC Plant.cpp)
target_link_libraries(Plant PUBLIC GameObject)

# 定义和链接 Sunflower 库
add_library(Sunflower STATIC Sunflower.cpp)
target_link_libraries(Sunflower PUBLIC Plant Sun)

# 定义和链接 HoldingSeed 库
add_library(HoldingSeed STATIC HoldingSeed.cpp)
target_link_libraries(HoldingSeed PUBLIC GameObject)

# 定义和链接 Peashooter 库
add_library(Peashooter STATIC Peashooter.cpp)
target_link_libraries(Peashooter PUBLIC Plant Pea)

# 定义和链接 Pea 库
add_library(Pea STATIC Pea.cpp)
target_link_libraries(Pea PUBLIC GameObject)

# 定义和链接 Zombie 库
add_library(Zombie STATIC Zombie.cpp)
target_link_libraries(Zombie PUBLIC GameObject)

# 定义和链接 RegularZombie 库
add_library(RegularZombie STATIC RegularZombie.cpp)
target_link_libraries(RegularZombie PUBLIC Zombie)

# 定义和链接 Wallnut 库
add_library(Wallnut STATIC Wallnut.cpp)
target_link_libraries(Wallnut PUBLIC Plant)

# 定义和链接 CherryBombSeed 库
add_library(CherryBombSeed STATIC CherryBombSeed.cpp)
target_link_libraries(CherryBombSeed PUBLIC SeedButton)

# 定义和链接 CherryBomb 库
add_library(CherryBomb STATIC CherryBomb.cpp)
target_link_libraries(CherryBomb PUBLIC Plant)

# 定义和链接 Shovel 库
add_library(Explosion STATIC Explosion.cpp)
target_link_libraries(Explosion PUBLIC GameObject)

# 定义和链接 Shovel 库
add_library(Shovel STATIC Shovel.cpp)
target_link_libraries(Shovel PUBLIC GameObject)
