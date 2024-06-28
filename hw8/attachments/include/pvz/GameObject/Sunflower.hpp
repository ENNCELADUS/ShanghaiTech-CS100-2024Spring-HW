#ifndef SUNFLOWER_HPP__
#define SUNFLOWER_HPP__

#include "pvz/GameObject/Plant.hpp"
#include "pvz/utils.hpp"

class Sunflower : public Plant {
public:
    Sunflower(int x, int y, int hp, GameWorld& gameworld);

    void Update() override;

private:
    /**
     * @brief The next time sunlight appears.
     */
    int nextSunGenerationTick;

    /**
     * @brief Sunlight generation interval
     */
    int sunGenerationInterval; 

    void GenerateSun();
};

#endif // SUNFLOWER_HPP__
