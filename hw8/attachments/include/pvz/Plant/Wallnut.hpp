#ifndef WALLNUT_HPP__
#define WALLNUT_HPP__

#include "pvz/Plant/Plant.hpp"

class Wallnut : public Plant {
public:
    Wallnut(int x, int y, GameWorld& gameworld);

    void Update() override;
    void OnClick() override;
};

#endif // WALLNUT_HPP__
