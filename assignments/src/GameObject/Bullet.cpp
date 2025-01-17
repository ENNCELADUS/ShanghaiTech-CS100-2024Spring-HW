#include "runaway/GameObject/Bullet.hpp"
#include "runaway/GameWorld/GameWorld.hpp"

// Constructor for Bullet
Bullet::Bullet(int x, int y, std::shared_ptr<GameWorld> world)
    : Projectile(ImageID::BULLET, x, y, LayerID::PROJECTILES, 10, 10, world, 1, 0, AnimID::NO_ANIMATION)
{
    moveSpeed = bulletSpeed; // Set the bullet's speed
}

// Override Update method to check for specific Bullet behavior
void Bullet::Update()
{
    if (!IsAlive())
    {
        return; // If the bullet is dead, stop further updates
    }

    // Move the bullet to the right
    Move();

    // If the bullet goes off-screen, set it to dead
    if (GetX() >= WINDOW_WIDTH)
    {
        SetHP(0); // Bullet dies when it goes off-screen
    }
}
