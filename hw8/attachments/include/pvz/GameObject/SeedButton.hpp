#ifndef SEEDBUTTON_HPP__
#define SEEDBUTTON_HPP__

#include "pvz/GameObject/GameObject.hpp"

class SeedButton : public GameObject {
public:
    SeedButton(ImageID imageID, int x, int y, int width, int height, int price, int cooldown, GameWorld& gameworld);

    virtual void Update() override;

    virtual void OnClick() override;

private:
    GameWorld& gameWorld;
    int price;
    int cooldown;
};

#endif // SEEDBUTTON_HPP__
