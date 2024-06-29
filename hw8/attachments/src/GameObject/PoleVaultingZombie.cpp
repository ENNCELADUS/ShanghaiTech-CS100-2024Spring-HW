#include "pvz/GameObject/PoleVaultingZombie.hpp"


PoleVaultingZombie::PoleVaultingZombie(int x, int y, GameWorld& gameworld)
    : Zombie(IMGID_POLE_VAULTING_ZOMBIE, x, y, 20, 80, 340, gameworld, ANIMID_RUN_ANIM), isRunning(true), jumpFrameCount(0) {}

void PoleVaultingZombie::Update() {
    if (IsDead()) {
        return;
    }

    if (isRunning) {
        // Temporarily move zombies to detect plants.
        MoveTo(GetX() - 40, GetY());

        // Detect collisions with plants
        bool collidedWithPlant = false;
        for (const auto& obj : gameWorld.GetGameObjects()) {
            if (obj->GetObjectType() == ObjectType::PLANT && Intersects(obj.get())) {
                collidedWithPlant = true;
                break;
            }
        }

        // Withdraw temporary move.
        MoveTo(GetX() + 40, GetY());

        if (collidedWithPlant) {
            // Stop moving and play the jump animation.
            PlayAnimation(ANIMID_JUMP_ANIM);
            jumpFrameCount = 42;
            isRunning = false;
            return;
        }

        if (jumpFrameCount > 0) {
            jumpFrameCount--;
            if (jumpFrameCount == 0) {
                PlayAnimation(ANIMID_WALK_ANIM);
                MoveTo(GetX() - 150, GetY());
            }
            return;
        }

        MoveTo(GetX() - 2, GetY());
    } 
    else {
        if (IsEating()) {
            return;
        }

        // Is walking.
        MoveTo(GetX() - 1, GetY());
    }
}

void PoleVaultingZombie::OnClick() {
    
}