#ifndef PROJECTILES_HPP__
#define PROJECTILES_HPP__

#include "runaway/GameObject/GameObject.hpp"
#include <memory>

class Projectile : public GameObject
{
public:
    // Constructor
    Projectile(ImageID imageID, int x, int y, LayerID layer, int width, int height, std::shared_ptr<GameWorld> world, int hp, int attack, AnimID animID);

    // Virtual update function to handle projectile behavior
    virtual void Update() override;

    // Common movement behavior for all projectiles
    void Move();

protected:
    int moveSpeed; // Movement speed of the projectile
};

#endif // !PROJECTILES_HPP__
