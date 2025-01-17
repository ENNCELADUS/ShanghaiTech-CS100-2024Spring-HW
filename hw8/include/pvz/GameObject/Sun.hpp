#ifndef SUN_HPP__
#define SUN_HPP__

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/utils.hpp"

class GameWorld;

class Sun : public GameObject {
public:
    /**
     * @brief Construct a new Sun object
     * 
     * @param x 
     * @param y 
     * @param fromSunflower 
     * @param gameworld 
     */
    Sun(int x, int y, bool fromSunflower, GameWorld& gameworld);

    void Update() override;
    void OnClick() override;

private:
    bool fromSunflower;
    int fallTime;
    int ticksSinceFalling;
    int verticalSpeed; // only for sunflower generated sun
    GameWorld& gameWorld;

    void initializeFallTime();
};

#endif // SUN_HPP__
