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

    PlantingSpot(int x, int y);

    void Update() override;

    void OnClick() override;
};

#endif // PLANTINGSPOT_HPP__
