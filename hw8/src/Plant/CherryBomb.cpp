#include "pvz/Plant/CherryBomb.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/Explosion.hpp"

CherryBomb::CherryBomb(int x, int y, GameWorld& gameworld)
    : Plant(IMGID_CHERRY_BOMB, x, y, 60, 80, 4000, gameworld, ANIMID_IDLE_ANIM), frameCount(0) {}

void CherryBomb::Update() {
    if (IsDead()) {
        return;
    }

    frameCount++;
    if (frameCount >= 15) {
        MarkAsDead();
        auto explosion = std::make_shared<Explosion>(GetX(), GetY(), gameWorld);
        gameWorld.AddGameObject(explosion);
    }
}