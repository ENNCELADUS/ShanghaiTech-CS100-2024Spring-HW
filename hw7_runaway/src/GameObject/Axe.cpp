#include "runaway/GameObject/Axe.hpp"
#include "runaway/GameWorld/GameWorld.hpp"
#include "runaway/GameObject/Player.hpp"

Axe::Axe(int x, int y, std::shared_ptr<GameWorld> world)
    : GameObject(ImageID::AXE, x, y, LayerID::PROJECTILES, WIDTH, HEIGHT, world, 1, 0, AnimID::NO_ANIMATION)
{
}

void Axe::Update()
{
    if (!IsAlive() || IsOffScreen())
    {
        SetHP(0);
        return;
    }

    Move();
}

void Axe::Move()
{
    MoveTo(GetX() - SPEED, GetY());
}

void Axe::OnCollision(std::shared_ptr<GameObject> other)
{
    if (other->GetType() == GameObject::Type::Player)
    {
        SetHP(0);
    }
}

bool Axe::IsOffScreen() const
{
    return GetX() <= 0;
}