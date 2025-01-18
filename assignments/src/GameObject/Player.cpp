#include "runaway/GameWorld/GameWorld.hpp"
#include "runaway/GameObject/Player.hpp"
#include "runaway/GameObject/Bullet.hpp"

// Constructor
Player::Player(std::shared_ptr<GameWorld> world)
    : GameObject(ImageID::PLAYER, 200, 120, LayerID::PLAYER, 20, 48, world, 10, 10, AnimID::IDLE),
      jumpFramesRemaining(0),
      fireCooldown(0) {}

// Update function
void Player::Update()
{
    if (!IsAlive())
    {
        return;
    }

    // Handle fire cooldown
    if (fireCooldown > 0)
    {
        fireCooldown--;
    }

    // Check for jump action
    if (jumpFramesRemaining > 0)
    {
        // Apply vertical motion based on jump physics
        int velocity = jumpSpeed - gravity * (jumpDuration - jumpFramesRemaining);
        MoveTo(GetX(), GetY() + velocity);
        jumpFramesRemaining--;

        if (jumpFramesRemaining == 0)
        {
            ResetToIdle();
        }
    }

    if (m_world->GetKeyDown(KeyCode::FIRE1))
    {
        Fire(); // Fire when left mouse button is clicked
    }

    if (m_world->GetKeyDown(KeyCode::JUMP))
    {
        Jump(); // Jump when spacebar is pressed
    }
}

// Check if the player is dead
bool Player::IsDead() const
{
    return !IsAlive();
}

// Handle firing
void Player::Fire()
{
    if (fireCooldown > 0)
        return;

    // Create a projectile object at player's position + offset
    m_world->Instantiate(std::make_shared<Bullet>(
        GetX() + 30, GetY(), m_world)); //

    // Set cooldown for firing
    fireCooldown = fireCooldownFrames;
}

// Handle jumping
void Player::Jump()
{
    if (jumpFramesRemaining > 0)
        return; // Prevent double jump

    jumpFramesRemaining = jumpDuration;
    PlayAnimation(AnimID::JUMP); // Switch to jump animation
}

// Reset animation to idle
void Player::ResetToIdle()
{
    PlayAnimation(AnimID::IDLE); // Switch to idle animation
}

// Handle collision
void Player::OnCollision(std::shared_ptr<GameObject> other)
{
    if (other->GetType() == GameObject::Type::ProjectileEnemy)
    {
        TakeDamage(1); // Player takes 1 damage from enemy projectiles
    }
    else if (other->GetType() == GameObject::Type::Enemy)
    {
        TakeDamage(1); // Player takes 100 damage from enemy
    }
}