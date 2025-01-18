#ifndef BULLET_HPP__
#define BULLET_HPP__

#include "runaway/GameObject/Projectiles.hpp"

class Bullet : public Projectile
{
public:
    // Constructor
    Bullet(int x, int y, std::shared_ptr<GameWorld> world);

    // Override Update method for Bullet-specific behavior
    void Update() override;

    // Override OnCollision method
    void OnCollision(std::shared_ptr<GameObject> other) override;

    // Getter for Type (to identify object type)
    GameObject::Type GetType() const override { return GameObject::Type::ProjectilePlayer; }

private:
    static constexpr int bulletSpeed = 10; // Bullet moves 10 pixels per frame
};

#endif // !BULLET_HPP__
