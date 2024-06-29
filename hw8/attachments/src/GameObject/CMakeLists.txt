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

add_library(
  Plant
  STATIC
  Plant.cpp
)

target_link_libraries(
  Plant
  PUBLIC
  GameObject
)

add_library(
  Sunflower
  STATIC
  Sunflower.cpp
)

target_link_libraries(
  Sunflower
  PUBLIC
  Plant
)

add_library(
  HoldingSeed
  STATIC
  HoldingSeed.cpp
)

target_link_libraries(
  HoldingSeed
  PUBLIC
  GameObject
)

add_library(
  Peashooter
  STATIC
  Peashooter.cpp
)

target_link_libraries(
  Peashooter
  PUBLIC
  Plant
)

add_library(
  Pea
  STATIC
  Pea.cpp
)

target_link_libraries(
  Pea
  PUBLIC
  GameObject
)

add_library(
  Zombie
  STATIC
  Zombie.cpp
)

target_link_libraries(
  Zombie
  PUBLIC
  GameObject
)

add_library(
  RegularZombie
  STATIC
  RegularZombie.cpp
)

target_link_libraries(
  RegularZombie
  PUBLIC
  Zombie
)

add_library(
  Wallnut
  STATIC
  Wallnut.cpp
)

target_link_libraries(
  Wallnut
  PUBLIC
  Plant
)

add_library(
  Shovel
  STATIC
  Shovel.cpp
)

target_link_libraries(
  Shovel
  PUBLIC
  GameObject
)

add_library(
  PoleVaultingZombie
  STATIC
  PoleVaultingZombie.cpp
)

target_link_libraries(
  PoleVaultingZombie
  PUBLIC
  Zombie
)