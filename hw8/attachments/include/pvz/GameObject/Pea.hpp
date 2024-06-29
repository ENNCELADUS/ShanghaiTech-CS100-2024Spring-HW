#ifndef PEA_HPP__
#define PEA_HPP__

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class Pea : public GameObject {
public:
    Pea(int x, int y, GameWorld& gameworld);

    void Update() override;
    void OnClick() override;

private:
    int speed = 8;
    GameWorld& gameWorld;

    /**
     * @brief Check whether Pea collises with a Zombie.
     */
    bool CheckCollisionWithZombies();
};

#endif // PEA_HPP__
