#include "pvz/GameObject/SeedButton.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/utils.hpp"


SeedButton::SeedButton(ImageID imageID, int x, int y, int width, int height, int price, int cooldown)
    : GameObject(imageID, x, y, LAYER_UI, width, height, ANIMID_NO_ANIMATION), price(price), cooldown(cooldown) {
}

void SeedButton::Update() {
    if (cooldownMask) {
        cooldownMask->Update();
    }
}

void SeedButton::OnClick() {
    // Check if the player is holding a shovel or an unplanted seed
    // TODO:

    // Check if there is enough sunlight
    if (GameWorld::GetSunlight() < price) {
        return;
    }

    // Spend sunlight and enter cooldown
    GameWorld::SpendSunlight(price);

    // Create cooldown mask
    cooldownMask = std::make_shared<CooldownMask>(GetX(), GetY());
    gameWorld->AddGameObject(cooldownMask);
    
    // Set the selected seed
    gameWorld->SetSelectedSeed(shared_from_this());
}
