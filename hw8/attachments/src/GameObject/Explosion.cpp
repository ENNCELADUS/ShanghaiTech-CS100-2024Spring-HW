#include "pvz/GameObject/Explosion.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

Explosion::Explosion(int x, int y, GameWorld& gameworld)
    : GameObject(IMGID_EXPLOSION, x, y, LAYER_PROJECTILES, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION), frameCount(0) {}

void Explosion::Update() {
    frameCount++;
    if (frameCount >= 3) {
        MarkAsDead();
    }
}

void Explosion::OnClick() {
    // Explosion does nothing when clicked.
}

bool Explosion::Intersects(GameObject* other) const {

    int explosionWidth = 3 * LAWN_GRID_WIDTH;
    int explosionHeight = 3 * LAWN_GRID_HEIGHT;

    int otherX = other->GetX();
    int otherY = other->GetY();
    int otherWidth = other->GetWidth();
    int otherHeight = other->GetHeight();

    int left = GetX() - explosionWidth / 2;
    int right = GetX() + explosionWidth / 2;
    int top = GetY() + explosionHeight / 2;
    int bottom = GetY() - explosionHeight / 2;

    return !(otherX + otherWidth / 2 < left || otherX - otherWidth / 2 > right || otherY - otherHeight / 2 > top || otherY + otherHeight / 2 < bottom);
}