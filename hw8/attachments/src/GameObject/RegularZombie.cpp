#include "pvz/GameObject/RegularZombie.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

RegularZombie::RegularZombie(int x, int y, GameWorld& gameworld)
    : Zombie(IMGID_REGULAR_ZOMBIE, x, y, 20, 80, 200, gameworld, ANIMID_WALK_ANIM) {}

void RegularZombie::Update() {
    if (IsDead()) {
        return;
    }

    if (isWalking) {
        MoveTo(GetX() - 1, GetY());
    }
}

void RegularZombie::OnClick() {
    
}

void RegularZombie::HandleCollision(std::shared_ptr<GameObject> other) {
    if (other->GetObjectType() == ObjectType::PLANT) {
        if (isWalking) {
            isWalking = false;
            PlayAnimation(ANIMID_EAT_ANIM);
        }
        other->TakeDamage(damageToPlant);
    } 
    else if (other->GetObjectType() == ObjectType::PEA) {
        TakeDamage(20);
        other->MarkAsDead();
    }
}