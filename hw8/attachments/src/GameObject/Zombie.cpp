#include "pvz/GameObject/Zombie.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/Plant.hpp"
#include "pvz/GameObject/Pea.hpp"

Zombie::Zombie(ImageID imageID, int x, int y, int width, int height, int hp, GameWorld& gameworld, AnimID animID)
    : GameObject(imageID, x, y, LAYER_ZOMBIES, width, height, animID, hp), gameWorld(gameworld) {}

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
