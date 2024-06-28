#ifndef HOLDINGSEED_HPP__
#define HOLDINGSEED_HPP__

#include "pvz/GameObject/GameObject.hpp"

enum class PlantType {
    Sunflower,
    Peashooter,
    Wallnut
};

class HoldingSeed : public GameObject {
public:
    HoldingSeed(PlantType plantType);

    PlantType GetPlantType() const;

    void Update() override;
    void OnClick() override;

private:
    PlantType plantType;
};

#endif // HOLDINGSEED_HPP__
