#include "runaway/GameObject/Axe.hpp"
#include "runaway/GameWorld/GameWorld.hpp"
#include "runaway/GameObject/Player.hpp" // For collision with player

// Constructor for Axe
Axe::Axe(int x, int y, std::shared_ptr<GameWorld> world)
    : Projectile(ImageID::AXE, x, y, LayerID::PROJECTILES, axeWidth, axeHeight, world, 1, 0, AnimID::NO_ANIMATION)
{
    moveSpeed = axeSpeed; // Set the axe's speed to move left
}

// Override Update method to handle Axe-specific behavior
void Axe::Update()
{
    if (!IsAlive())
    {
        return; // If the axe is dead, stop further updates
    }

    // Move the axe to the left by 'moveSpeed' pixels
    Move();

    // If the axe goes off the screen on the left, set it to dead
    if (GetX() <= 0)
    {
        SetHP(0); // Axe dies when it goes off-screen
    }
}
