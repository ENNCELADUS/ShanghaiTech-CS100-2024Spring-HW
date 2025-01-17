#include "pvz/Environment/PlantingSpot.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/utils.hpp"

/**
 * @brief Construct a new PlantingSpot object.
 * 
 * @param x The x-coordinate of the planting spot.
 * @param y The y-coordinate of the planting spot.
 */
PlantingSpot::PlantingSpot(int x, int y, GameWorld& gameworld)
    : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, 1, ObjectType::PLANT_SLOT), gameWorld(gameworld) {}


void PlantingSpot::Update() {
    // No update logic for planting spot
}


void PlantingSpot::OnClick() {
    gameWorld.PlantSeed(GetX(), GetY());
}
