#ifndef SEEDBUTTON_HPP__
#define SEEDBUTTON_HPP__

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameObject/CooldownMask.hpp"
#include <memory>

class SeedButton : public GameObject {
public:
    SeedButton(ImageID imageID, int x, int y, int width, int height, int price, int cooldown);

    virtual void Update() override;

    virtual void OnClick() override;

protected:
    int price;       // The price of the seed in sunlight
    int cooldown;    // The cooldown time in ticks
    std::shared_ptr<CooldownMask> cooldownMask; // The cooldown mask
};

#endif // SEEDBUTTON_HPP__
