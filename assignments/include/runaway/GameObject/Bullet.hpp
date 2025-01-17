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

private:
    static constexpr int bulletSpeed = 10; // Bullet moves 10 pixels per frame
};

#endif // !BULLET_HPP__
