#include "runaway/GameObject/Bullet.hpp"
#include "runaway/GameWorld/GameWorld.hpp"

Bullet::Bullet(int x, int y, std::shared_ptr<GameWorld> world)
    : GameObject(ImageID::BULLET, x, y, LayerID::PROJECTILES, SIZE, SIZE, world, 1, 0, AnimID::NO_ANIMATION)
{
}

void Bullet::Update()
{
    if (!IsAlive() || IsOffScreen())
    {
        SetHP(0);
        return;
    }

    Move();
}

void Bullet::Move()
{
    MoveTo(GetX() + SPEED, GetY());
}

void Bullet::OnCollision(std::shared_ptr<GameObject> other)
{
    if (other->GetType() == GameObject::Type::Enemy)
    {
        SetHP(0);
    }
}

bool Bullet::IsOffScreen() const
{
    return GetX() >= WINDOW_WIDTH;
}