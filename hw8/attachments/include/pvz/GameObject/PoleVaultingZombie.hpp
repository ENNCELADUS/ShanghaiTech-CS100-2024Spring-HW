#ifndef POLEVAULTINGZOMBIE_HPP__
#define POLEVAULTINGZOMBIE_HPP__

#include "pvz/GameObject/Zombie.hpp"

class PoleVaultingZombie : public Zombie {
public:
    PoleVaultingZombie(int x, int y, GameWorld& gameworld);

    void Update() override;
    void OnClick() override;

private:
    bool isRunning = true;
    int jumpFrameCount = 0;
};

#endif // POLEVAULTINGZOMBIE_HPP__
