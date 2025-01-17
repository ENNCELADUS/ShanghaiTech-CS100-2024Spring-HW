#include "pvz/SeedButton/WallnutSeed.hpp"
#include "pvz/utils.hpp"

WallnutSeed::WallnutSeed(int x, int y, GameWorld& gameworld, PlantType Wallnut)
    : SeedButton(IMGID_SEED_WALLNUT, x, y, 50, 70, 50, 900, gameworld, PlantType::Wallnut) {
}
