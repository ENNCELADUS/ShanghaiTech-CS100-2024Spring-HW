#include "runaway/GameWorld/GameWorld.hpp"
#include "runaway/GameObject/Player.hpp"
#include "runaway/GameObject/Bullet.hpp"

Player::Player(std::shared_ptr<GameWorld> world)
    : GameObject(ImageID::PLAYER, 200, 120, LayerID::PLAYER, 20, 48, world, 10, 10, AnimID::IDLE) {}

void Player::Update()
{
    if (!IsAlive())
        return;

    if (fireCooldown > 0)
        fireCooldown--;

    UpdateJump();
    HandleInput();
}

void Player::UpdateJump()
{
    if (jumpFramesRemaining > 0)
    {
        int velocity = jumpSpeed - gravity * (jumpDuration - jumpFramesRemaining);
        MoveTo(GetX(), GetY() + velocity);
        jumpFramesRemaining--;

        if (jumpFramesRemaining == 0)
            ResetToIdle();
    }
}

void Player::HandleInput()
{
    if (m_world->GetKeyDown(KeyCode::FIRE1))
        Fire();
    if (m_world->GetKeyDown(KeyCode::JUMP))
        Jump();
}

bool Player::IsDead() const
{
    return !IsAlive();
}

void Player::Fire()
{
    if (fireCooldown > 0)
        return;

    m_world->Instantiate(std::make_shared<Bullet>(GetX() + 30, GetY(), m_world));
    fireCooldown = fireCooldownFrames;
}

void Player::Jump()
{
    if (jumpFramesRemaining > 0)
        return;

    jumpFramesRemaining = jumpDuration;
    PlayAnimation(AnimID::JUMP);
}

void Player::ResetToIdle()
{
    PlayAnimation(AnimID::IDLE);
}

void Player::OnCollision(std::shared_ptr<GameObject> other)
{
    if (other->GetType() == GameObject::Type::ProjectileEnemy ||
        other->GetType() == GameObject::Type::Enemy)
    {
        TakeDamage(1);
    }
}