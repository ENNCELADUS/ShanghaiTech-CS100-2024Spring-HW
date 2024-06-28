#include "pvz/GameObject/Sunflower.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

Sunflower::Sunflower(int x, int y, int hp, GameWorld& gameworld)
    : Plant(IMGID_SUNFLOWER, x, y, 60, 80, 300, gameworld, ANIMID_IDLE_ANIM), nextSunGenerationTick(randInt(30, 600)), sunGenerationInterval(600) {}

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
