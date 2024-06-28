#ifndef PLANTINGSPOT_HPP__
#define PLANTINGSPOT_HPP__

#include "pvz/GameObject/GameObject.hpp"

/**
 * @brief The PlantingSpot class, inheriting from GameObject.
 * 
 * Represents a planting spot on the lawn.
 */
class PlantingSpot : public GameObject {
public:

    PlantingSpot(int x, int y, GameWorld& gameworld);

    void Update() override;

    void OnClick() override;

private:
    GameWorld& gameWorld;
};

#endif // PLANTINGSPOT_HPP__
