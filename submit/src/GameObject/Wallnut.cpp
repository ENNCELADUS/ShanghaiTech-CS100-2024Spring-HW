#include "pvz/GameObject/Wallnut.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

Wallnut::Wallnut(int x, int y, GameWorld& gameworld)
    : Plant(IMGID_WALLNUT, x, y, 60, 80, 4000, gameworld, ANIMID_IDLE_ANIM) {}

void Wallnut::Update() {
    if (IsDead()) {
        return;
    }

    Plant::Update();

    if (hp < 4000 / 3) {
        ChangeImage(IMGID_WALLNUT_CRACKED);
    }
}

void Wallnut::OnClick() {
    if (gameWorld.IsHoldingShovel()) {
        MarkAsDead();
        gameWorld.SetHoldingShovel(false);
    }
}
