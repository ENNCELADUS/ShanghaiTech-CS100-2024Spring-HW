#ifndef EXPLOSION_HPP__
#define EXPLOSION_HPP__

#include "GameObject.hpp"

class Explosion : public GameObject {
public:
    Explosion(int x, int y, GameWorld& gameworld);

    void Update() override;
    void OnClick() override;
    bool Intersects(GameObject* other) const override;

private:
    int frameCount;
};

#endif // EXPLOSION_HPP__
