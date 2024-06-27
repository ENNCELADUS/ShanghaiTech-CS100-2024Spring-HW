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
  // Initialize statistics.
  sunlight = 100, currentWave = 0;

  CreateTexts();

  CreateBackground();

  CreatePlantingSpot();

  CreateSeedButtons();

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

  // Update the texts
  UpdateText();

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // TODO:
  gameObjects.clear();
}


int GameWorld::GetSunlight() const {
  return sunlight;
}
int GameWorld::GetCurrentWave() const {
  return currentWave;
}

void GameWorld::CreateTexts(){
  sunlightText = std::make_shared<TextBase>(60, WINDOW_HEIGHT - 80, "100");
  waveText = std::make_shared<TextBase>(WINDOW_WIDTH - 80, 10, "Wave: 0");
}

void GameWorld::CreateBackground(){
  auto background = std::make_shared<Background>();
  gameObjects.push_back(background);
}

void GameWorld::CreatePlantingSpot(){
  for (int row = 0; row < GAME_ROWS; row++) {
    for (int col = 0; col < GAME_COLS; col++) {
      int x = FIRST_COL_CENTER + col * LAWN_GRID_WIDTH;
      int y = FIRST_ROW_CENTER + row * LAWN_GRID_HEIGHT;
      auto spot = std::make_shared<PlantingSpot>(x, y);
      gameObjects.push_back(spot);
    }
  }
}

void GameWorld::CreateSeedButtons() {
  int x = 130;
  int y = WINDOW_HEIGHT - 44;

  auto sunflowerSeed = std::make_shared<SunflowerSeed>(x, y);
  gameObjects.push_back(sunflowerSeed);

  x += 60;
  auto peashooterSeed = std::make_shared<PeashooterSeed>(x, y);
  gameObjects.push_back(peashooterSeed);

  x += 60;
  auto wallnutSeed = std::make_shared<WallnutSeed>(x, y);
  gameObjects.push_back(wallnutSeed);

  x += 60;
  auto cherryBombSeed = std::make_shared<CherryBombSeed>(x, y);
  gameObjects.push_back(cherryBombSeed);

  x += 60;
  auto repeaterSeed = std::make_shared<RepeaterSeed>(x, y);
  gameObjects.push_back(repeaterSeed);
}


void GameWorld::SpendSunlight(int amount) {
  sunlight -= amount;
  if (sunlight < 0) {
    sunlight = 0;
  }
}

bool GameWorld::IsHoldingShovel() const {
  // Implement logic to check if the player is holding a shovel
  // TODO:
  return false; // Placeholder
}


bool GameWorld::IsHoldingSeed() const {
  return selectedSeed != nullptr;
}


void GameWorld::SetSelectedSeed(std::shared_ptr<GameObject> seed) {
  selectedSeed = seed;
}


void GameWorld::AddGameObject(std::shared_ptr<GameObject> obj) {
  gameObjects.push_back(obj);
}


void GameWorld::UpdateText() {
  sunlightText->SetText(std::to_string(sunlight));
  waveText->SetText("Wave: " + std::to_string(currentWave));
}