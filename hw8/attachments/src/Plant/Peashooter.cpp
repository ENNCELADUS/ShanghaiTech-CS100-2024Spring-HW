#include "pvz/Plant/Peashooter.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/Pea.hpp"


Peashooter::Peashooter(int x, int y, GameWorld& gameworld)
    : Plant(IMGID_PEASHOOTER, x, y, 60, 80, 300, gameworld, ANIMID_IDLE_ANIM), cooldown(0) {}

void Peashooter::Update() {
    if (IsDead()) {
        return;
    }

    Plant::Update();

    if (cooldown > 0) {
        cooldown--;
        return;
    }

    if (gameWorld.HasZombiesInRow(GetY(), GetX())) {
        FirePea();
        cooldown = attackCooldown;
    }
}

void Peashooter::FirePea() {
    auto pea = std::make_shared<Pea>(GetX() + 30, GetY() + 20, gameWorld);
    gameWorld.AddGameObject(pea);
}
