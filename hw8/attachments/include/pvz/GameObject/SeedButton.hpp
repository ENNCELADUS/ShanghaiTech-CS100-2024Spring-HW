#ifndef SEEDBUTTON_HPP__
#define SEEDBUTTON_HPP__

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameObject/HoldingSeed.hpp"

class SeedButton : public GameObject {
public:
    SeedButton(ImageID imageID, int x, int y, int width, int height, int price, int cooldown, GameWorld& gameworld, PlantType PlantType);

    virtual void Update() override;

    virtual void OnClick() override;

protected:
    PlantType plantType;
    GameWorld& gameWorld;
    int price;
    int cooldown;
};

#endif // SEEDBUTTON_HPP__
