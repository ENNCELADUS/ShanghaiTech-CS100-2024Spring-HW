#ifndef COOLDOWNMASK_HPP__
#define COOLDOWNMASK_HPP__

#include "GameObject.hpp"

class CooldownMask : public GameObject {
public:
    CooldownMask(int x, int y, int coolDown);

    void Update() override;
    void OnClick() override;

private:
    int cooldownRemaining;
};

#endif // COOLDOWNMASK_HPP__
