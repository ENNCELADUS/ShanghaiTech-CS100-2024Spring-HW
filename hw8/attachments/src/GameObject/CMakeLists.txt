cmake_minimum_required(VERSION 3.16)

# 定义和链接 GameObject 库
add_library(GameObject STATIC GameObject.cpp)
target_link_libraries(GameObject PUBLIC Framework)

# 定义和链接 CooldownMask 库
add_library(CooldownMask STATIC CooldownMask.cpp)
target_link_libraries(CooldownMask PUBLIC GameObject)

# 定义和链接 Sun 库
add_library(Sun STATIC Sun.cpp)
target_link_libraries(Sun PUBLIC GameObject)

# 定义和链接 HoldingSeed 库
add_library(HoldingSeed STATIC HoldingSeed.cpp)
target_link_libraries(HoldingSeed PUBLIC GameObject)

# 定义和链接 Pea 库
add_library(Pea STATIC Pea.cpp)
target_link_libraries(Pea PUBLIC GameObject)

# 定义和链接 Explosion 库
add_library(Explosion STATIC Explosion.cpp)
target_link_libraries(Explosion PUBLIC GameObject)

# 定义和链接 Shovel 库
add_library(Shovel STATIC Shovel.cpp)
target_link_libraries(Shovel PUBLIC GameObject)
