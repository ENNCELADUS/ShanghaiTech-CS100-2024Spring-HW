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

    if (CheckCollisionWithZombies()) {
        MarkAsDead();
    }
}

void Pea::OnClick() {
    // Do nothing.
}

bool Pea::CheckCollisionWithZombies() {
    for (const auto& obj : gameWorld.GetGameObjects()) {
        if (obj->GetLayer() == LAYER_ZOMBIES && std::abs(obj->GetX() - GetX()) < 10 && std::abs(obj->GetY() - GetY()) < 10) {
            if (auto zombie = std::dynamic_pointer_cast<Zombie>(obj)) {
                zombie->HandleCollision(GetpGameObject());
                return true;
            }
        }
    }
    return false;
}