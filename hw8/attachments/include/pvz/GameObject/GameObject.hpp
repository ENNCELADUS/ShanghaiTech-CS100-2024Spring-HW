#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "pvz/Framework/ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

/**
 * @brief The GameObject class, inheriting from ObjectBase and std::enable_shared_from_this.
 * Represents a generic game object that can be managed in the game world.
 */
class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".

  /**
   * @brief Construct a new Game Object object
   * 
   * @param imageID The image ID for the game object.
   * @param x The x-coordinate of the game object.
   * @param y The y-coordinate of the game object.
   * @param layer The display layer of the game object.
   * @param width The width of the game object.
   * @param height The height of the game object.
   * @param animID The animation ID for the game object.
   */
  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);
  virtual ~GameObject() = default;

  virtual void Update() = 0;
  virtual void OnClick() = 0;

  /**
   * @brief Check if the game object is dead.
   * 
   * @return true if the game object is dead, false otherwise.
   */
  bool IsDead() const;
  /**
   * @brief Mark the game object as dead.
   */
  void MarkAsDead();


private:
  bool isDead;
};


#endif // !GAMEOBJECT_HPP__
