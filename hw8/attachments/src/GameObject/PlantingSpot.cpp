#include "pvz/GameObject/PlantingSpot.hpp"
#include "pvz/utils.hpp"

/**
 * @brief Construct a new PlantingSpot object.
 * 
 * @param x The x-coordinate of the planting spot.
 * @param y The y-coordinate of the planting spot.
 */
PlantingSpot::PlantingSpot(int x, int y)
    : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION) {}


void PlantingSpot::Update() {
    // No update logic for planting spot
}


void PlantingSpot::OnClick() {
    // TODO:Logic to plant a plant when the spot is clicked
}
