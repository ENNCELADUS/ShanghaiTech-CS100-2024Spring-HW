#ifndef CHERRYBOMB_HPP__
#define CHERRYBOMB_HPP__

#include "pvz/GameObject/Plant.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class CherryBomb : public Plant {
public:
    CherryBomb(int x, int y, GameWorld& gameworld);

    void Update() override;

private:
    int frameCount;
};

#endif // CHERRYBOMB_HPP__
