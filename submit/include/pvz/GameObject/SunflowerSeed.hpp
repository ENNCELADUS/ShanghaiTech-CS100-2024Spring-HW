#ifndef SUNFLOWERSEED_HPP__
#define SUNFLOWERSEED_HPP__

#include "SeedButton.hpp"

class SunflowerSeed : public SeedButton {
public:
    SunflowerSeed(int x, int y, GameWorld& gameworld, PlantType Sunflower);
};

#endif // SUNFLOWERSEED_HPP__
