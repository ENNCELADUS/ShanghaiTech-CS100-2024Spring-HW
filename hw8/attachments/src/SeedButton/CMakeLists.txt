cmake_minimum_required(VERSION 3.16)

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

# 定义和链接 CherryBombSeed 库
add_library(CherryBombSeed STATIC CherryBombSeed.cpp)
target_link_libraries(CherryBombSeed PUBLIC SeedButton)