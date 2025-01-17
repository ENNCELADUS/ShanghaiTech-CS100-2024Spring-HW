#include "pvz/Plant/Sunflower.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/Sun.hpp"

Sunflower::Sunflower(int x, int y, GameWorld& gameworld)
    : Plant(IMGID_SUNFLOWER, x, y, 60, 80, 300, gameworld, ANIMID_IDLE_ANIM), nextSunGenerationTick(gameworld.GetTickCount() + randInt(30, 600)) {}

void Sunflower::Update() {
    if (IsDead()) {
        return;
    }

    Plant::Update();

    if (!IsDead() && Plant::gameWorld.GetTickCount() >= nextSunGenerationTick) {
        GenerateSun();
        nextSunGenerationTick += sunGenerationInterval;
    }
}

void Sunflower::GenerateSun() {
    Plant::gameWorld.AddGameObject(std::make_shared<Sun>(GetX(), GetY(), true, gameWorld));
}
