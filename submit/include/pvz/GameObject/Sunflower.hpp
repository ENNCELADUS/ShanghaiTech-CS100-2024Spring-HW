#ifndef SUNFLOWER_HPP__
#define SUNFLOWER_HPP__

#include "pvz/GameObject/Plant.hpp"
#include "pvz/utils.hpp"

class Sunflower : public Plant {
public:
    Sunflower(int x, int y, GameWorld& gameworld);

    void Update() override;

private:
    /**
     * @brief The next time sunlight appears.
     */
    int nextSunGenerationTick;

    /**
     * @brief Sunlight generation interval
     */
    int sunGenerationInterval = 600; 

    void GenerateSun();
};

#endif // SUNFLOWER_HPP__
