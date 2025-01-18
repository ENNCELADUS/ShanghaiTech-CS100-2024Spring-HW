#ifndef PLAYER_HPP__
#define PLAYER_HPP__

#include <memory>
#include "runaway/GameObject/GameObject.hpp"

class Player : public GameObject
{
public:
    // Constructor
    Player(std::shared_ptr<GameWorld> world);

    // Override the Update function
    void Update() override;

    // Check if the player is dead
    bool IsDead() const;

    // Handle firing
    void Fire();

    // Handle jumping
    void Jump();

    GameObject::Type GetType() const override { return GameObject::Type::Player; }

private:
    // Jump and firing mechanics
    int jumpFramesRemaining = 0;
    int fireCooldown = 0;

    // Constants
    static constexpr int jumpSpeed = 23;
    static constexpr int gravity = 2;
    static constexpr int jumpDuration = 24;
    static constexpr int fireCooldownFrames = 10;

    // Reset animation to idle
    void ResetToIdle();
};

#endif // !PLAYER_HPP__
