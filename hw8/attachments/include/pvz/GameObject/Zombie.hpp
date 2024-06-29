#ifndef ZOMBIE_HPP__
#define ZOMBIE_HPP__

#include "pvz/GameObject/GameObject.hpp"

class GameWorld;

class Zombie : public GameObject {
public:
    Zombie(ImageID imageID, int x, int y, int width, int height, int hp, GameWorld& gameworld, AnimID animID);
    void Update() override;
    void OnClick() override;
    void TakeDamage(int damage) override;
    void HandleNoCollision() override;

    /**
     * @brief Handle collision with another game object.
     * 
     * @param other The other game object.
     */
    virtual void HandleCollision(std::shared_ptr<GameObject> other);

    bool IsEating() const;
    void StopEating();

protected:
    GameWorld& gameWorld;
    bool isWalking;
};

#endif // ZOMBIE_HPP__
