#ifndef SHOVEL_HPP__
#define SHOVEL_HPP__

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class Shovel : public GameObject {
public:
    Shovel(GameWorld& gameworld);

    void Update() override;
    void OnClick() override;

private:
    GameWorld& gameWorld;
};

#endif // SHOVEL_HPP__
