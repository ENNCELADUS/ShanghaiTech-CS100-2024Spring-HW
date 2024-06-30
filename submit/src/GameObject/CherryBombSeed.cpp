#include "pvz/GameObject/CherryBombSeed.hpp"

CherryBombSeed::CherryBombSeed(int x, int y, GameWorld& gameworld, PlantType CherryBomb)
    : SeedButton(IMGID_SEED_CHERRY_BOMB, x, y, 50, 70, 150, 1200, gameworld, PlantType::CherryBomb) {}