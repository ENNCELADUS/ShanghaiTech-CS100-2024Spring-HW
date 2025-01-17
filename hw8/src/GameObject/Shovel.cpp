#include "pvz/GameObject/Shovel.hpp"
#include "pvz/utils.hpp"

Shovel::Shovel(GameWorld& gameworld)
    : GameObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION), gameWorld(gameworld) {}

void Shovel::Update() {
    // Shovel does nothing on update
}

void Shovel::OnClick() {
    if (gameWorld.GetHoldingSeed()) {
        return;
    }

    if (gameWorld.IsHoldingShovel()) {
        gameWorld.SetHoldingShovel(false);
    } 
    
    else {
        gameWorld.SetHoldingShovel(true);
    }
}
