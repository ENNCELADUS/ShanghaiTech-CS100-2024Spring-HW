add_library(Background STATIC
  Background.cpp
)

target_include_directories(Background PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(PlantingSpot STATIC
  PlantingSpot.cpp
)

target_include_directories(PlantingSpot PUBLIC ${CMAKE_SOURCE_DIR}/include)
