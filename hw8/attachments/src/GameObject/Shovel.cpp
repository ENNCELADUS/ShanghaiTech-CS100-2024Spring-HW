#include "pvz/GameObject/Shovel.hpp"
#include "pvz/utils.hpp"

Shovel::Shovel(GameWorld& gameworld)
    : GameObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION), gameWorld(gameworld) {}

void Shovel::Update() {
    // Shovel does nothing on update
}

void Shovel::OnClick() {
    if (gameWorld.GetHoldingSeed()) {
        /**
         * @brief If the player is holding a seed, ignore the click
         */
        return;
    }

    if (gameWorld.IsHoldingShovel()) {
        /**
         * @brief If the player is already holding the shovel, put it down
         */
        gameWorld.SetHoldingShovel(false);
    } else {
        /**
         * @brief If the player is not holding the shovel, pick it up
         */
        gameWorld.SetHoldingShovel(true);
    }
}
