cmake_minimum_required(VERSION 3.16)

add_library(
  GameObject
  STATIC
  GameObject.cpp
)

target_link_libraries(
  GameObject
  Framework
)

add_library(
  Background 
  STATIC 
  Background.cpp
)

target_link_libraries(
  Background 
  PUBLIC 
  GameObject
)

add_library(
  PlantingSpot 
  STATIC 
  PlantingSpot.cpp
)

target_link_libraries(
  PlantingSpot 
  PUBLIC 
  GameObject
)

add_library(
  SeedButton
  STATIC 
  SeedButton.cpp
)

target_link_libraries(
  SeedButton 
  PUBLIC 
  GameObject
)

add_library(
  SunflowerSeed
  STATIC
  SunflowerSeed.cpp
)

target_link_libraries(
  SunflowerSeed
  PUBLIC
  SeedButton
)

# 添加PeashooterSeed库
add_library(
  PeashooterSeed
  STATIC
  PeashooterSeed.cpp
)

target_link_libraries(
  PeashooterSeed
  PUBLIC
  SeedButton
)

add_library(
  WallnutSeed
  STATIC
  WallnutSeed.cpp
)

target_link_libraries(
  WallnutSeed
  PUBLIC
  SeedButton
)

add_library(
  CooldownMask
  STATIC
  CooldownMask.cpp
)

target_link_libraries(
  CooldownMask
  PUBLIC
  GameObject
)

add_library(
  Sun
  STATIC
  Sun.cpp
)

target_link_libraries(
  Sun
  PUBLIC
  GameObject
)
