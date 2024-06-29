#ifndef REGULARZOMBIE_HPP__
#define REGULARZOMBIE_HPP__

#include "pvz/GameObject/Zombie.hpp"

class RegularZombie : public Zombie {
public:
    RegularZombie(int x, int y, GameWorld& gameworld);

    void Update() override;
    void OnClick() override;
    void HandleCollision(std::shared_ptr<GameObject> other) override;

private:
    bool isWalking;
    int damageToPlant = 3;
};

#endif // REGULARZOMBIE_HPP__
