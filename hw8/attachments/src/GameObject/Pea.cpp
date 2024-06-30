#include "pvz/GameObject/Pea.hpp"
#include "pvz/GameObject/Zombie.hpp"

Pea::Pea(int x, int y, GameWorld& gameworld)
    : GameObject(IMGID_PEA, x, y, LAYER_PROJECTILES, 28, 28, ANIMID_NO_ANIMATION, 1, ObjectType::PEA), gameWorld(gameworld) {}

void Pea::Update() {
    if (IsDead()) {
        return;
    }

    MoveTo(GetX() + speed, GetY());

    if (GetX() >= WINDOW_WIDTH) {
        MarkAsDead();
        return;
    }
}

void Pea::OnClick() {
    // Do nothing.
}