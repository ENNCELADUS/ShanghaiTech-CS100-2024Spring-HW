#include "runaway/GameObject/Enemies.hpp"
#include "runaway/GameObject/Projectiles.hpp"
#include "runaway/GameWorld/GameWorld.hpp"
#include "runaway/GameObject/Axe.hpp"

// Constructor for Goblin
Goblin::Goblin(int x, int y, std::shared_ptr<GameWorld> world)
    : GameObject(ImageID::GOBLIN, x, y, LayerID::ENEMIES, 20, 48, world, 5, 0, AnimID::IDLE)
{
    // Initialize goblin properties
}

// Update function for Goblin
void Goblin::Update()
{
    if (!IsAlive())
    {
        // If the goblin is dead, stop further updates
        return;
    }

    // Move the goblin to the left by 'moveSpeed' pixels
    MoveTo(GetX() - moveSpeed, GetY());

    // 3. Every 100 ticks, start the process of throwing the axe
    if (ticks % 100 == 0)
    {
        // Play the THROW animation at the start of the 100-tick interval
        PlayAnimation(AnimID::THROW);
    }

    // 4. Wait 20 ticks after starting the THROW animation to actually throw the axe
    if (ticks % 100 == 20) // This happens exactly 20 ticks after the start
    {
        ThrowAxe(); // Throws the axe

        // 5. Change the animation back to IDLE immediately after throwing the axe
        PlayAnimation(AnimID::IDLE);
    }

    ticks++;
}

// Handle throwing an axe
void Goblin::ThrowAxe()
{
    // Create an Axe object at the goblin's position + offset (as per your design)
    m_world->Instantiate(std::make_shared<Axe>(GetX() - 30, GetY(), m_world)); // Axe thrown 30 pixels to the left of the goblin
}

// Handle collision with other game objects
void Goblin::OnCollision(std::shared_ptr<GameObject> other)
{
    // Handle collision behavior based on the type of the other object
    if (other->GetType() == GameObject::Type::ProjectilePlayer)
    {
        // If the goblin is hit by a player projectile, reduce its HP based on the bullet's attack
        TakeDamage(1); // Assuming the bullet deals 1 damage to the goblin
    }
    else if (other->GetType() == GameObject::Type::Player)
    {
        // If the goblin collides with the player, the goblin dies and the player takes 1 point of damage
        SetHP(0); // Mark the goblin as dead
    }
}
