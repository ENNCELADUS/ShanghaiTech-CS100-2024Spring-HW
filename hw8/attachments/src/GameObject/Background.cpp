#include "pvz/GameObject/Background.hpp"
#include "pvz/utils.hpp"

/**
 * @brief Construct a new Background object.
 */
Background::Background()
    : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION) {}

/**
 * @brief Background does nothing on update.
 */
void Background::Update() {
    
}

/**
 * @brief Background does nothing on click.
 */
void Background::OnClick() {
    
}
