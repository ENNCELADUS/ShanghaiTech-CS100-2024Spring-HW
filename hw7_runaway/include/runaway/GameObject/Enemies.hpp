#ifndef ENEMIES_HPP__

#define ENEMIES_HPP__

#include <memory>

#include "runaway/GameObject/GameObject.hpp"
#include "runaway/GameWorld/GameWorld.hpp"

class Goblin : public GameObject
{
public:
    // Constructor for Goblin
    Goblin(int x, int y, std::shared_ptr<GameWorld> world);

    // Update method for Goblin
    void Update() override;

    // Handle axe throwing after animation
    void ThrowAxe();

    GameObject::Type GetType() const override { return GameObject::Type::Enemy; }

    void OnCollision(std::shared_ptr<GameObject> other) override;

private:
    unsigned int ticks = 0;             // Track ticks for axe throwing
    static constexpr int moveSpeed = 3; // Goblin moves 3 pixels per frame to the left
};

#endif // !ENEMIES_HPP__