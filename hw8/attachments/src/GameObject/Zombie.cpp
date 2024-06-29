#include "pvz/GameObject/Zombie.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/Plant.hpp"
#include "pvz/GameObject/Pea.hpp"

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

void HandleCollision(std::shared_ptr<GameObject> other) {

}