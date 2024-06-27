#include "pvz/GameObject/SeedButton.hpp"
#include "pvz/utils.hpp"

#include <iostream>

SeedButton::SeedButton(ImageID imageID, int x, int y, int width, int height, int price, int cooldown)
    : GameObject(imageID, x, y, LAYER_UI, width, height, ANIMID_NO_ANIMATION), price(price), cooldown(cooldown), cooldownRemaining(0) {
}

void SeedButton::Update() {
    if (cooldownRemaining > 0) {
        --cooldownRemaining;
    }
}

void SeedButton::OnClick() {
    if (cooldownRemaining > 0) {
        return; // Seed is still cooling down
    }
    // TODO:
}
