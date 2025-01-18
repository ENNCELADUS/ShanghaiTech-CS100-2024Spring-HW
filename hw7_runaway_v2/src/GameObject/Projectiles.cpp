#include "runaway/GameObject/Projectiles.hpp"

// Constructor for Projectile (base class)
Projectile::Projectile(ImageID imageID, int x, int y, LayerID layer, int width, int height, std::shared_ptr<GameWorld> world, int hp, int attack, AnimID animID)
    : GameObject(imageID, x, y, layer, width, height, world, hp, attack, animID), moveSpeed(10) {}

// Update function (can be overridden by derived classes like Bullet and Axe)
void Projectile::Update()
{
    if (!IsAlive())
    {
        return; // If projectile is dead, stop further updates
    }

    Move(); // Move the projectile (common logic for all projectiles)
}

// Common movement logic for projectiles (move to the right)
void Projectile::Move()
{
    MoveTo(GetX() + moveSpeed, GetY()); // Move the projectile to the right
}
