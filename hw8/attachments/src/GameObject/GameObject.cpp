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
GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : ObjectBase(imageID, x, y, layer, width, height, animID), isDead(false) {}

/**
 * @brief Check if the game object is dead.
 * 
 * @return true if the game object is dead, false otherwise.
 */
bool GameObject::IsDead() const {
    return isDead;
}

/**
 * @brief Mark the game object as dead.
 */
void GameObject::MarkAsDead() {
    isDead = true;
}