#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "pvz/Framework/ObjectBase.hpp"

enum class ObjectType {
  PLANT,
  ZOMBIE,
  PEA,
  PLANT_SLOT,
  EXPLOSION,
  OTHER
};

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
   * @param hp The health points for the game object.
   * @param type The type of the game object.
   */
  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, int hp = 1, ObjectType type = ObjectType::OTHER);
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

  /**
   * @brief Get the Layer of the game object.
   * 
   * @return LayerID of the game object.
   */
  LayerID GetLayer() const;

  /**
   * @brief Get the shared pointer to this object.
   * 
   * @return std::shared_ptr<GameObject>
   */
  std::shared_ptr<GameObject> GetpGameObject();

  /**
   * @brief Get the type of the game object.
   * 
   * @return ObjectType of the game object.
   */
  ObjectType GetObjectType() const;

  /**
   * @brief Get the Hp.
   */
  int GetHp() const;

  /**
   * @brief Apply damage to the game object.
   * 
   * @param damage The amount of damage to apply.
   */
  virtual void TakeDamage(int damage);

  /**
   * @brief Check if this object intersects with another object.
   * 
   * @param other The other game object to check for intersection.
   * @return true if the objects intersect, false otherwise.
   */
  virtual bool Intersects(GameObject* other) const;

  /**
   * @brief Handle the situation where the object does not collide with a specific type of object.
   */
  virtual void HandleNoCollision();

protected:
  int hp;
  ObjectType objectType;

private:
  bool isDead;
  LayerID Layer;
};


#endif // !GAMEOBJECT_HPP__
