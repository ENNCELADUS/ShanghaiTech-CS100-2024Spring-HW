#include "pvz/GameObject/Sun.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include <iostream>

Sun::Sun(int x, int y, bool fromSunflower, GameWorld& gameworld)
    : GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM), fromSunflower(fromSunflower), ticksSinceFalling(0), gameWorld(gameworld) {
    if (fromSunflower) {
        fallTime = 12;
        verticalSpeed = 4;
    } 
    else {
        initializeFallTime();
    }
}

void Sun::initializeFallTime() {
    fallTime = randInt(63, 263);
}

void Sun::Update() {
    if (ticksSinceFalling < fallTime) {
        if (fromSunflower) {
            // From sunflower.
            MoveTo(GetX() - 1, GetY() + verticalSpeed);
            verticalSpeed -= 1;
        } 
        else {
            // From sky.
            MoveTo(GetX(), GetY() - 2);
        }
        ticksSinceFalling++;
    } 
    else if (ticksSinceFalling < fallTime + 300) {
        ticksSinceFalling++;
    } 
    else {
        MarkAsDead();
    }
}

void Sun::OnClick() {
    gameWorld.AddSunlight(25);
    MarkAsDead(); 
}
