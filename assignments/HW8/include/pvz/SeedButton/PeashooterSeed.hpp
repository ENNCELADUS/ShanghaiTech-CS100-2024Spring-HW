#ifndef PEASHOOTERSEED_HPP__
#define PEASHOOTERSEED_HPP__

#include "SeedButton.hpp"

class PeashooterSeed : public SeedButton {
public:
    PeashooterSeed(int x, int y, GameWorld& gameworld, PlantType Peashooter);
};

#endif // PEASHOOTERSEED_HPP__
