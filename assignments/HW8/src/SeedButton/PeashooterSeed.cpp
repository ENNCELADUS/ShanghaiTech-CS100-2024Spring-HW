#include "pvz/SeedButton/PeashooterSeed.hpp"
#include "pvz/utils.hpp"

PeashooterSeed::PeashooterSeed(int x, int y, GameWorld& gameworld, PlantType Peashooter)
    : SeedButton(IMGID_SEED_PEASHOOTER, x, y, 50, 70, 100, 240, gameworld, PlantType::Peashooter) {}
