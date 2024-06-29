#include "pvz/GameObject/Plant.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

Plant::Plant(ImageID imageID, int x, int y, int width, int height, int hp, GameWorld& gameworld, AnimID animID)
    : GameObject(imageID, x, y, LAYER_PLANTS, width, height, ANIMID_IDLE_ANIM, hp, ObjectType::PLANT), gameWorld(gameworld) {}

/**
 * @brief Judge whether a plant is dead.
 * 
 */
void Plant::Update() {
    if (hp <= 0) {
        MarkAsDead();
    }
}

void Plant::OnClick() {
    if (gameWorld.IsHoldingShovel()) {
        MarkAsDead();
        gameWorld.SetHoldingShovel(false);
    }
}

void Plant::TakeDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        MarkAsDead();
    }
}