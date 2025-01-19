#ifndef PLAYER_HPP__
#define PLAYER_HPP__

#include <memory>
#include "runaway/GameObject/GameObject.hpp"

class Player : public GameObject
{
public:
    Player(std::shared_ptr<GameWorld> world);
    void Update() override;
    bool IsDead() const;
    void Fire();
    void Jump();
    void OnCollision(std::shared_ptr<GameObject> other) override;
    GameObject::Type GetType() const override { return GameObject::Type::Player; }

private:
    void ResetToIdle();
    void UpdateJump();
    void HandleInput();

    int jumpFramesRemaining = 0;
    int fireCooldown = 0;

    static const int jumpSpeed = 23;
    static const int gravity = 2;
    static const int jumpDuration = 24;
    static const int fireCooldownFrames = 10;
};

#endif // !PLAYER_HPP__
