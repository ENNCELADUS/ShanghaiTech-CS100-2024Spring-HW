#ifndef BULLET_HPP__
#define BULLET_HPP__

#include "runaway/GameObject/GameObject.hpp"
#include <memory>

class Bullet : public GameObject
{
public:
    Bullet(int x, int y, std::shared_ptr<GameWorld> world);

    void Update() override;
    void OnCollision(std::shared_ptr<GameObject> other) override;
    GameObject::Type GetType() const override { return GameObject::Type::ProjectilePlayer; }

private:
    void Move();
    bool IsOffScreen() const;

    static constexpr int SPEED = 10;
    static constexpr int SIZE = 10;
};

#endif // BULLET_HPP__