#include "pvz/GameObject/SunflowerSeed.hpp"
#include "pvz/utils.hpp"

SunflowerSeed::SunflowerSeed(int x, int y, GameWorld& gameworld)
    : SeedButton(IMGID_SEED_SUNFLOWER, x, y, 50, 70, 50, 240, gameworld) {}
