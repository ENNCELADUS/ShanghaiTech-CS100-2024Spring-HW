#ifndef PLANT_HPP__
#define PLANT_HPP__

#include "pvz/GameObject/GameObject.hpp"

class Plant : public GameObject {
public:
    Plant(ImageID imageID, int x, int y, int width, int height, int hp, GameWorld& gameworld, AnimID animID);
    virtual void Update() override;
    virtual void OnClick() override;
    void TakeDamage(int damage) override;

protected:
    GameWorld& gameWorld;
};

#endif // PLANT_HPP__
