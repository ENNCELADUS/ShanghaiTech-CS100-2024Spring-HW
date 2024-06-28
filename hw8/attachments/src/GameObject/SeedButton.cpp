#include "pvz/GameObject/SeedButton.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/utils.hpp"


SeedButton::SeedButton(ImageID imageID, int x, int y, int width, int height, int price, int cooldown, GameWorld& gameworld)
    : GameObject(imageID, x, y, LAYER_UI, width, height, ANIMID_NO_ANIMATION), price(price), cooldown(cooldown), gameWorld(gameworld) {}

void SeedButton::Update() {
  
}

void SeedButton::OnClick() {
    // TODO:

    // Check if the player is holding a shovel or an unplanted seed
    if (gameWorld.IsHoldingShovel() || gameWorld.IsHoldingSeed()) {
        return;
    }

    // Check if there is enough sunlight
    if (gameWorld.GetSunlight() < price) {
        return;
    }

    // Spend sunlight and enter cooldown
    gameWorld.SpendSunlight(price);

    // Create cooldown mask
    gameWorld.AddGameObject(std::make_shared<CooldownMask>(GetX(), GetY()));
    
}