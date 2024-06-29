#include "pvz/GameWorld/GameWorld.hpp"


/**
 * @brief Construct a new Game World:: Game World object
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

  tickCount++;
  if ((tickCount - 180) % 300 == 0) {
      CreateSun();
  }

  // TODO:
  

  /**
   * @brief Update all game objects
   */
  for (auto& gameObject : gameObjects) {
    gameObject->Update();
  }

  // Iterate and delete game objects marked dead.
  for (auto it = gameObjects.begin(); it != gameObjects.end(); ) {
    if ((*it)->IsDead()) {
      it = gameObjects.erase(it);
    } else {
      ++it;
    }
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
int GameWorld::GetTickCount() const {
  return tickCount;
}

void GameWorld::CreateTexts(){
  sunlightText = std::make_shared<TextBase>(60, WINDOW_HEIGHT - 80, "100");
  waveText = std::make_shared<TextBase>(WINDOW_WIDTH - 80, 10, "Wave: 0");
}

void GameWorld::CreateBackground(){
  auto background = std::make_shared<Background>();
  AddGameObject(background);
}

void GameWorld::CreatePlantingSpot(){
  for (int row = 0; row < GAME_ROWS; row++) {
    for (int col = 0; col < GAME_COLS; col++) {
      int x = FIRST_COL_CENTER + col * LAWN_GRID_WIDTH;
      int y = FIRST_ROW_CENTER + row * LAWN_GRID_HEIGHT;
      auto spot = std::make_shared<PlantingSpot>(x, y, *shared_from_this());
      AddGameObject(spot);
    }
  }
}

void GameWorld::CreateSeedButtons() {
  int x = 130;
  int y = WINDOW_HEIGHT - 44;

  auto sunflowerSeed = std::make_shared<SunflowerSeed>(x, y, *shared_from_this(), PlantType::Sunflower);
  AddGameObject(sunflowerSeed);

  x += 60;
  auto peashooterSeed = std::make_shared<PeashooterSeed>(x, y, *shared_from_this(), PlantType::Peashooter);
  AddGameObject(peashooterSeed);

  x += 60;
  auto wallnutSeed = std::make_shared<WallnutSeed>(x, y, *shared_from_this(), PlantType::Wallnut);
  AddGameObject(wallnutSeed);
}

void GameWorld::CreateSun() {
  int x = randInt(75, WINDOW_WIDTH - 75);
  int y = WINDOW_HEIGHT - 1;
  auto sun = std::make_shared<Sun>(x, y, false, *this);
  AddGameObject(sun);
}


void GameWorld::SpendSunlight(int amount) {
  sunlight -= amount;
  if (sunlight < 0) {
    sunlight = 0;
  }
}

void GameWorld::AddSunlight(int amount) {
  sunlight += amount;
}

bool GameWorld::IsHoldingShovel() const {
  // Implement logic to check if the player is holding a shovel
  // TODO:
  return false; // Placeholder
}

void GameWorld::SetHoldingShovel(bool holding) {
  holdingShovel = holding;
}

void GameWorld::SetHoldingSeed(std::shared_ptr<HoldingSeed> seed) {
  holdingSeed = seed;
}

std::shared_ptr<HoldingSeed> GameWorld::GetHoldingSeed() const {
  return holdingSeed;
}

// TODO:
void GameWorld::PlantSeed(int x, int y) {
  if (holdingSeed) {
    auto plantType = holdingSeed->GetPlantType();
    std::shared_ptr<GameObject> plant;

    switch (plantType) {
      case PlantType::Sunflower:
        plant = std::make_shared<Sunflower>(x, y, *this);
        break;
      case PlantType::Peashooter:
        plant = std::make_shared<Peashooter>(x, y, *this);
        break;
      // case PlantType::Wallnut:
      //   plant = std::make_shared<Wallnut>(x, y, *this);
      //   break;
    }

    if (plant) {
      AddGameObject(plant);
    }

    holdingSeed = nullptr;
  }
}



void GameWorld::AddGameObject(std::shared_ptr<GameObject> obj) {
  gameObjects.push_back(obj);
}

const std::list<std::shared_ptr<GameObject>>& GameWorld::GetGameObjects() const {
  return gameObjects;
}

void GameWorld::UpdateText() {
  sunlightText->SetText(std::to_string(sunlight));
  waveText->SetText("Wave: " + std::to_string(currentWave));
}

bool GameWorld::HasZombiesInRow(int y, int x) const {
  for (const auto& obj : gameObjects) {
    if (obj->GetLayer() == LAYER_ZOMBIES && obj->GetY() == y && obj->GetX() > x) {
      return true;
    }
  }
  return false;
}