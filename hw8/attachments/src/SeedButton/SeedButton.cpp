#include "pvz/SeedButton/SeedButton.hpp"
#include "pvz/GameObject/CooldownMask.hpp"
#include "pvz/GameWorld/GameWorld.hpp"


SeedButton::SeedButton(ImageID imageID, int x, int y, int width, int height, int price, int cooldown, GameWorld& gameworld, PlantType plantType)
    : GameObject(imageID, x, y, LAYER_UI, width, height, ANIMID_NO_ANIMATION), price(price), cooldown(cooldown), gameWorld(gameworld), plantType(plantType) {}

void SeedButton::Update() {
  
}

void SeedButton::OnClick() {
    // TODO:

    // Check if the player is holding a shovel or an unplanted seed
    if (gameWorld.IsHoldingShovel() || (gameWorld.GetHoldingSeed() != nullptr) ) {
        return;
    }

    // Check if there is enough sunlight
    if (gameWorld.GetSunlight() < price) {
        return;
    }

    // Spend sunlight and enter cooldown
    gameWorld.SpendSunlight(price);

    // Create cooldown mask
    auto cooldownMask = std::make_shared<CooldownMask>(GetX(), GetY(), cooldown);
    gameWorld.AddGameObject(cooldownMask);

    gameWorld.SetHoldingSeed(std::make_shared<HoldingSeed>(plantType));
}
