#include "pvz/GameObject/WallnutSeed.hpp"
#include "pvz/utils.hpp"

WallnutSeed::WallnutSeed(int x, int y, GameWorld& gameworld)
    : SeedButton(IMGID_SEED_WALLNUT, x, y, 50, 70, 50, 900, gameworld) {
}
