#include "pvz/GameWorld/GameWorld.hpp"


/**
 * @brief Construct a new Game World:: Game World object
 */
GameWorld::GameWorld() 
  : sunlight(300), currentWave(0){}

GameWorld::~GameWorld() {}

/**
 * @brief Initialize the game world.
 * 
 */
void GameWorld::Init() {
  // Initialize statistics.
  sunlight = 300, currentWave = 0;

  CreateTexts();

  CreateBackground();

  CreatePlantingSpot();

  CreateSeedButtons();

  CreateShovel();
}

LevelStatus GameWorld::Update() {
  tickCount++;

  /**
   * @brief Step 1: Drop new sunlight
   */
  if ((tickCount + 150) % 300 == 0) {
      CreateSun();
  }

  /**
   * @brief Step 2: Generate new zombies
   */
  CreateZombies();

  /**
   * @brief Step 3: Update all game objects
   */
  for (auto& gameObject : gameObjects) {
    gameObject->Update();
  }

  /**
   * @brief Step 4: Handle collisions.
   */
  HandleCollisions();

  /**
   * @brief Step 5: Iterate and delete game objects marked dead.
   */
  for (auto it = gameObjects.begin(); it != gameObjects.end(); ) {
    if ((*it)->IsDead() || ((*it)->GetHp() == 0)) {
      it = gameObjects.erase(it);
    } else {
      ++it;
    }
  }

  /**
   * @brief Step 6: Check for level failure
   */
  for (const auto& gameObject : gameObjects) {
    if (gameObject->GetObjectType() == ObjectType::ZOMBIE && gameObject->GetX() < 0) {
      return LevelStatus::LOSING;
    }
  }

  /**
   * @brief Step 7: Check for zombie collision with plants
   */
  for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
    if ((*it)->GetObjectType() == ObjectType::ZOMBIE) {
      bool collidedWithPlant = false;
      for (auto it2 = gameObjects.begin(); it2 != gameObjects.end(); ++it2) {
        if ((*it2)->GetObjectType() == ObjectType::PLANT && (*it)->Intersects((*it2).get())) {
          collidedWithPlant = true;
          break;
        }
      }
      if (!collidedWithPlant) {
        auto zombie = std::dynamic_pointer_cast<Zombie>(*it);
        if (zombie) {
          zombie->HandleNoCollision();
        }
      }
    }
  }

  /**
   * @brief Step 8: Update the texts. 
   */
  UpdateText();

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  gameObjects.clear();

  // Reset sunlight, wave, and tick count
  sunlight = 300;
  currentWave = 0;
  tickCount = 0;

  // Clear holding states
  holdingSeed = nullptr;
  holdingShovel = false;

  // Clear texts
  sunlightText = nullptr;
  waveText = nullptr;
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

  x += 60;
  auto cherryBombSeed = std::make_shared<CherryBombSeed>(x, y, *shared_from_this(), PlantType::CherryBomb);
  AddGameObject(cherryBombSeed);
}

void GameWorld::CreateShovel() {
  AddGameObject(std::make_shared<Shovel>(*shared_from_this()));
}

void GameWorld::CreateSun() {
  int x = randInt(75, WINDOW_WIDTH - 75);
  int y = WINDOW_HEIGHT - 1;
  auto sun = std::make_shared<Sun>(x, y, false, *this);
  AddGameObject(sun);
}

void GameWorld::CreateZombies() {
  if (tickCount >= 1200 && (tickCount - 1200) % std::max(150, 600 - 20 * currentWave) == 0) {
    currentWave++;
    int numZombies = (15 + currentWave) / 10;
    for (int i = 0; i < numZombies; i++) {
      /**
       * @brief Calculate the possibility of generating zombies.
       */
      int P1 = 20;
      // int P2 = 2 * std::max(currentWave - 2, 0);
      // int P3 = 3 * std::max(currentWave - 15, 0);
      int totalP = P1;

      int randVal = randInt(1, totalP);
      std::shared_ptr<Zombie> zombie;

      enum ZombieType { REGULAR, POLE_VAULTING, BUCKETHEAD };
      ZombieType zombieType;
      if (randVal <= P1) {
        zombieType = REGULAR;
      } 
      // else if (randVal <= P1 + P2) {
      //   zombieType = POLE_VAULTING;
      // }
      // } else {
      //   zombieType = BUCKETHEAD;
      // }

      // DONE:
      switch (zombieType) {
        case REGULAR:
          zombie = std::make_shared<RegularZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), 
            FIRST_ROW_CENTER + randInt(0, GAME_ROWS - 1) * LAWN_GRID_HEIGHT, *this);
          break;

        // case POLE_VAULTING:
        //   zombie = std::make_shared<PoleVaultingZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), 
        //     FIRST_ROW_CENTER + randInt(0, GAME_ROWS - 1) * LAWN_GRID_HEIGHT, *this);
        //   break;

        // case BUCKETHEAD:
        //   zombie = std::make_shared<BucketheadZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), 
        //     FIRST_ROW_CENTER + randInt(0, GAME_ROWS - 1) * LAWN_GRID_HEIGHT, *this);
        //   break;
      }

      AddGameObject(zombie);
    }
  }
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
  return holdingShovel; 
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
      case PlantType::Wallnut:
        plant = std::make_shared<Wallnut>(x, y, *this);
        break;
      case PlantType::CherryBomb:
        plant = std::make_shared<CherryBomb>(x, y, *this);
        break;
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
    if (obj->GetObjectType() == ObjectType::ZOMBIE && obj->GetY() == y && obj->GetX() > x) {
      return true;
    }
  }
  return false;
}


void GameWorld::HandleCollisions() {
  // Handle collisions between zombies and peas
  for (auto it1 = gameObjects.begin(); it1 != gameObjects.end(); ++it1) {
    if ((*it1)->GetObjectType() == ObjectType::ZOMBIE) {
      for (auto it2 = gameObjects.begin(); it2 != gameObjects.end(); ++it2) {
        if ((*it2)->GetObjectType() == ObjectType::PEA) {
          if ((*it1)->Intersects((*it2).get())) {
            auto zombie = std::dynamic_pointer_cast<Zombie>(*it1);
            if (zombie) {
              zombie->HandleCollision(*it2);
            }
          }
        }
      }
    }
  }

  // Handle collisions between explosions and zombies
  for (auto it1 = gameObjects.begin(); it1 != gameObjects.end(); ++it1) {
    if (auto explosion = std::dynamic_pointer_cast<Explosion>(*it1)) {
      for (auto it2 = gameObjects.begin(); it2 != gameObjects.end(); ++it2) {
        if ((*it2)->GetObjectType() == ObjectType::ZOMBIE) {
          if (explosion->Intersects((*it2).get())) {
            (*it2)->MarkAsDead();
          }
        }
      }
    }
  }

  // Handle collisions between zombies and plants
  for (auto it1 = gameObjects.begin(); it1 != gameObjects.end(); ++it1) {
    if ((*it1)->GetObjectType() == ObjectType::ZOMBIE) {
      for (auto it2 = gameObjects.begin(); it2 != gameObjects.end(); ++it2) {
        if ((*it2)->GetObjectType() == ObjectType::PLANT) {
          if ((*it1)->Intersects((*it2).get())) {
            auto zombie = std::dynamic_pointer_cast<Zombie>(*it1);
            if (zombie) {
              zombie->HandleCollision(*it2);
            }
          }
        }
      }
    }
  }

  // Handle cases where zombies are not colliding with plants
  for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
    if ((*it)->GetObjectType() == ObjectType::ZOMBIE) {
      bool collidedWithPlant = false;
      for (auto it2 = gameObjects.begin(); it2 != gameObjects.end(); ++it2) {
        if ((*it2)->GetObjectType() == ObjectType::PLANT && (*it)->Intersects((*it2).get())) {
          collidedWithPlant = true;
          break;
        }
      }
      if (!collidedWithPlant) {
        auto zombie = std::dynamic_pointer_cast<Zombie>(*it);
        if (zombie) {
          zombie->HandleNoCollision();
        }
      }
    }
  }
}