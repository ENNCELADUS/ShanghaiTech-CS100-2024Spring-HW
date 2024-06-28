#include "pvz/GameObject/CooldownMask.hpp"
#include "pvz/utils.hpp"

CooldownMask::CooldownMask(int x, int y)
    : GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION), cooldownRemaining(240) {}

void CooldownMask::Update() {
    if (cooldownRemaining > 0) {
        --cooldownRemaining;
        std::cout << cooldownRemaining << std::endl;
    } 
    else {
        // Remove the cooldown mask once the cooldown is complete
        GameObject::MarkAsDead();
        std::cout << "Dead" << std::endl;
        return;
    }
}

void CooldownMask::OnClick() {
    // Do nothing on click
}
