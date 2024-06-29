#include "pvz/GameObject/Zombie.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

Zombie::Zombie(ImageID imageID, int x, int y, int width, int height, int hp, GameWorld& gameworld, AnimID animID)
    : GameObject(imageID, x, y, LAYER_ZOMBIES, width, height, animID, hp, ObjectType::ZOMBIE), gameWorld(gameworld), isWalking(true) {}

void Zombie::Update() {
    if (hp <= 0) {
        MarkAsDead();
    }
}

void Zombie::OnClick() {
    
}

void Zombie::TakeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        MarkAsDead();
    }
}

bool Zombie::IsEating() const {
    return !isWalking;
}

void Zombie::StopEating() {
    isWalking = true;
    PlayAnimation(ANIMID_WALK_ANIM);
}

void Zombie::HandleNoCollision() {
    if (IsEating()) {
        StopEating();
    }
}

void Zombie::HandleCollision(std::shared_ptr<GameObject> other) {
    if (other->GetObjectType() == ObjectType::PEA) {
        TakeDamage(20);
        other->MarkAsDead();
    } else if (other->GetObjectType() == ObjectType::PLANT) {
        if (!IsEating()) {
            isWalking = false;
            PlayAnimation(ANIMID_EAT_ANIM);
        }
        other->TakeDamage(3); // 每次 Update 扣 3 点 HP
    }
}