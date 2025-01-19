#include "runaway/GameObject/Enemies.hpp"
#include "runaway/GameWorld/GameWorld.hpp"
#include "runaway/GameObject/Axe.hpp"

Goblin::Goblin(int x, int y, std::shared_ptr<GameWorld> world)
    : GameObject(ImageID::GOBLIN, x, y, LayerID::ENEMIES, 20, 48, world, 5, 0, AnimID::IDLE)
{
}

void Goblin::Update()
{
    if (!IsAlive())
        return;

    UpdateMovement();
    UpdateAttack();
    ticks++;
}

void Goblin::UpdateMovement()
{
    MoveTo(GetX() - moveSpeed, GetY());
}

void Goblin::UpdateAttack()
{
    if (ticks % attackInterval == 0)
    {
        PlayAnimation(AnimID::THROW);
    }
    else if (ticks % attackInterval == throwDelay)
    {
        ThrowAxe();
        PlayAnimation(AnimID::IDLE);
    }
}

void Goblin::ThrowAxe()
{
    m_world->Instantiate(std::make_shared<Axe>(GetX() - 30, GetY(), m_world));
}

void Goblin::OnCollision(std::shared_ptr<GameObject> other)
{
    switch (other->GetType())
    {
    case GameObject::Type::ProjectilePlayer:
        TakeDamage(1);
        break;
    case GameObject::Type::Player:
        SetHP(0);
        break;
    default:
        break;
    }
}