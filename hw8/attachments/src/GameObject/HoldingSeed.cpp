#include "pvz/GameObject/HoldingSeed.hpp"

HoldingSeed::HoldingSeed(PlantType plantType)
    : GameObject(IMGID_NONE, 0, 0, LAWN_GRID_HEIGHT, 0, 0, ANIMID_NO_ANIMATION), plantType(plantType) {}

PlantType HoldingSeed::GetPlantType() const {
    return plantType;
}

void HoldingSeed::Update() {
    // No implementation needed for HoldingSeed
}

void HoldingSeed::OnClick() {
    // No implementation needed for HoldingSeed
}