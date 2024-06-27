#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/Background.hpp"

/**
 * @brief Construct a new Game World:: Game World object
 * 
 */
GameWorld::GameWorld() 
  : sunlight(100), currentWave(0){}

GameWorld::~GameWorld() {}

/**
 * @brief Initialize the game world.
 * 
 */
void GameWorld::Init() {
  sunlight = 100, currentWave = 0;

  sunlightText = std::make_shared<TextBase>(60, WINDOW_HEIGHT - 80, "100");
  waveText = std::make_shared<TextBase>(WINDOW_WIDTH - 80, 10, "Wave: 0");

  auto background = std::make_shared<Background>();
  gameObjects.push_back(background);

  // TODO:
}

LevelStatus GameWorld::Update() {
  // TODO:
  /**
   * @brief Update all game objects
   * 
   * @param gameObjects 
   */
  for (auto& gameObject : gameObjects) {
    gameObject->Update();
  }

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // TODO:
  gameObjects.clear();
}

/**
 * @brief Getter
 * 
 * @return int 
 */
int GameWorld::GetSunlight() const {
  return sunlight;
}
int GameWorld::GetCurrentWave() const {
  return currentWave;
}

/**
 * @brief Update the text objects with the current sunlight and wave values.
 */
void GameWorld::UpdateText() {
  sunlightText->SetText(std::to_string(sunlight));
  waveText->SetText("Wave: " + std::to_string(currentWave));
}