#include "pvz/GameObject/GameObject.hpp"

/**
 * @brief Construct a new GameObject object.
 * 
 * @param imageID The image ID for the game object.
 * @param x The x-coordinate of the game object.
 * @param y The y-coordinate of the game object.
 * @param layer The display layer of the game object.
 * @param width The width of the game object.
 * @param height The height of the game object.
 * @param animID The animation ID for the game object.
 */
GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, int hp)
    : ObjectBase(imageID, x, y, layer, width, height, animID), isDead(false), Layer(layer), hp(hp) {}


bool GameObject::IsDead() const {
    return isDead;
}

void GameObject::MarkAsDead() {
    isDead = true;
}

LayerID GameObject::GetLayer() const {
    return Layer;
}

std::shared_ptr<GameObject> GameObject::GetpGameObject() {
    return shared_from_this();
}

void GameObject::TakeDamage(int damage) {

}
