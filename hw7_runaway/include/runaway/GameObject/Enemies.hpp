#ifndef ENEMIES_HPP__
#define ENEMIES_HPP__

#include <memory>
#include "runaway/GameObject/GameObject.hpp"
#include "runaway/GameWorld/GameWorld.hpp"

class Goblin : public GameObject
{
public:
    Goblin(int x, int y, std::shared_ptr<GameWorld> world);
    void Update() override;
    GameObject::Type GetType() const override { return GameObject::Type::Enemy; }
    void OnCollision(std::shared_ptr<GameObject> other) override;

private:
    void ThrowAxe();
    void UpdateMovement();
    void UpdateAttack();

    unsigned int ticks = 0;
    static constexpr int moveSpeed = 3;
    static constexpr int attackInterval = 100;
    static constexpr int throwDelay = 20;
};

#endif // !ENEMIES_HPP__