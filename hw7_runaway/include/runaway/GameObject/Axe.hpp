#ifndef AXE_HPP__
#define AXE_HPP__

#include "runaway/GameObject/GameObject.hpp"
#include <memory>

class Axe : public GameObject
{
public:
    Axe(int x, int y, std::shared_ptr<GameWorld> world);

    void Update() override;
    void OnCollision(std::shared_ptr<GameObject> other) override;
    GameObject::Type GetType() const override { return GameObject::Type::ProjectileEnemy; }

private:
    void Move();
    bool IsOffScreen() const;

    static constexpr int SPEED = 10;
    static constexpr int WIDTH = 25;
    static constexpr int HEIGHT = 25;
};

#endif // AXE_HPP__