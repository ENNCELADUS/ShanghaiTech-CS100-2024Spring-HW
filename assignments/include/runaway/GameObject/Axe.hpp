#ifndef AXE_HPP__
#define AXE_HPP__

#include "runaway/GameObject/Projectiles.hpp"
#include <memory>

class Axe : public Projectile
{
public:
    // Constructor
    Axe(int x, int y, std::shared_ptr<GameWorld> world);

    // Override Update method for Axe-specific behavior
    void Update() override;

    // Override Move to move the axe to the left
    void Move() override;

private:
    static constexpr int axeSpeed = 10;  // Axe moves 10 pixels per frame to the left
    static constexpr int axeWidth = 25;  // Axe width
    static constexpr int axeHeight = 25; // Axe height
};

#endif // !AXE_HPP__