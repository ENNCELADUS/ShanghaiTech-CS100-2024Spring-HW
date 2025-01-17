cmake_minimum_required(VERSION 3.16)

# 定义和链接 Plant 库
add_library(Plant STATIC Plant.cpp)
target_link_libraries(Plant PUBLIC GameObject)

# 定义和链接 Sunflower 库
add_library(Sunflower STATIC Sunflower.cpp)
target_link_libraries(Sunflower PUBLIC Plant Sun)

# 定义和链接 Peashooter 库
add_library(Peashooter STATIC Peashooter.cpp)
target_link_libraries(Peashooter PUBLIC Plant Pea)

# 定义和链接 Wallnut 库
add_library(Wallnut STATIC Wallnut.cpp)
target_link_libraries(Wallnut PUBLIC Plant)

# 定义和链接 CherryBomb 库
add_library(CherryBomb STATIC CherryBomb.cpp)
target_link_libraries(CherryBomb PUBLIC Plant)
