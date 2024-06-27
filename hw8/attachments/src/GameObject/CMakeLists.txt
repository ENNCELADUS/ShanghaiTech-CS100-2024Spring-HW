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