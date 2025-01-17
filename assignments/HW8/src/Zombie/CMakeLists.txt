cmake_minimum_required(VERSION 3.16)

# 定义和链接 Zombie 库
add_library(Zombie STATIC Zombie.cpp)
target_link_libraries(Zombie PUBLIC GameObject)

# 定义和链接 RegularZombie 库
add_library(RegularZombie STATIC RegularZombie.cpp)
target_link_libraries(RegularZombie PUBLIC Zombie)