#ifndef BACKGROUND_HPP__
#define BACKGROUND_HPP__

#include <memory>
#include "pvz/GameObject/GameObject.hpp"

/**
 * @brief The Background class, inheriting from GameObject.
 * 
 * Represents the background object in the game.
 */
class Background : public GameObject {
public:
    Background();

    void Update() override;

    void OnClick() override;
};

#endif // !BACKGROUND_HPP__
