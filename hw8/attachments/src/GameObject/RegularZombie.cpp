#include "pvz/GameObject/RegularZombie.hpp"
#include "pvz/GameObject/Plant.hpp"
#include "pvz/GameObject/Pea.hpp"

RegularZombie::RegularZombie(int x, int y, GameWorld& gameworld)
    : Zombie(IMGID_REGULAR_ZOMBIE, x, y, 20, 80, 200, gameworld, ANIMID_WALK_ANIM) {}

void RegularZombie::Update() {
    if (IsDead()) {
        return;
    }

    if (isWalking) {
        MoveTo(GetX() - 1, GetY());
    }

    for (const auto& obj : gameWorld.GetGameObjects()) {
        if (obj.get() != this && std::abs(obj->GetX() - GetX()) < 10 && std::abs(obj->GetY() - GetY()) < 10) {
            HandleCollision(obj);
        }
    }
}

void RegularZombie::OnClick() {
    
}

void RegularZombie::HandleCollision(std::shared_ptr<GameObject> other) {
    if (other->GetObjectType() == ObjectType::PLANT) {
        if (auto plant = std::dynamic_pointer_cast<Plant>(other)) {
            if (isWalking) {
                isWalking = false;
                PlayAnimation(ANIMID_EAT_ANIM);
            }
            plant->TakeDamage(damageToPlant);
        }
    } 
    else if (other->GetObjectType() == ObjectType::PEA) {
        if (auto pea = std::dynamic_pointer_cast<Pea>(other)) {
            TakeDamage(20);
            pea->MarkAsDead();
        }
    }
}