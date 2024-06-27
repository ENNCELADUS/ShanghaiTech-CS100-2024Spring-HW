#include "pvz/GameWorld/GameWorld.hpp"

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
  /**
   * @brief Initialize statistics.
   */
  sunlight = 100, currentWave = 0;

  /**
   * @brief Create texts.
   */
  sunlightText = std::make_shared<TextBase>(60, WINDOW_HEIGHT - 80, "100");
  waveText = std::make_shared<TextBase>(WINDOW_WIDTH - 80, 10, "Wave: 0");

  /**
   * @brief Create background.
   */
  auto background = std::make_shared<Background>();
  gameObjects.push_back(background);

  /**
   * @brief Create planting spots.
   */
  for (int row = 0; row < GAME_ROWS; row++) {
    for (int col = 0; col < GAME_COLS; col++) {
      int x = FIRST_COL_CENTER + col * LAWN_GRID_WIDTH;
      int y = FIRST_ROW_CENTER + row * LAWN_GRID_HEIGHT;
      auto spot = std::make_shared<PlantingSpot>(x, y);
      gameObjects.push_back(spot);
    }
  }


  /**
   * @brief Create Seed Buttons
   */
  int x = 130;
  int y = WINDOW_HEIGHT - 44;
  gameObjects.push_back(std::make_shared<SunflowerSeed>(x, y));
  x += 60;
  gameObjects.push_back(std::make_shared<PeashooterSeed>(x, y));
  x += 60;
  gameObjects.push_back(std::make_shared<WallnutSeed>(x, y));
  x += 60;
  gameObjects.push_back(std::make_shared<CherryBombSeed>(x, y));
  x += 60;
  gameObjects.push_back(std::make_shared<RepeaterSeed>(x, y));

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