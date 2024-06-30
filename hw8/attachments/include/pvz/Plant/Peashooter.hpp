#ifndef PEASHOOTER_HPP__
#define PEASHOOTER_HPP__

#include "pvz/Plant/Plant.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class Peashooter : public Plant {
public:
    Peashooter(int x, int y, GameWorld& gameworld);

    void Update() override;

private:
    int cooldown;
    static const int attackCooldown = 30;

    void FirePea();
};

#endif // PEASHOOTER_HPP__
