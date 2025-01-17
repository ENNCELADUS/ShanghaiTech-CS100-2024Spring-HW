#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <algorithm>
#include <iostream>
#include <list>
#include <memory>

#include "pvz/Framework/WorldBase.hpp"

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/Environment/Background.hpp"
#include "pvz/Environment/PlantingSpot.hpp"
#include "pvz/SeedButton/SeedButton.hpp"
#include "pvz/SeedButton/SunflowerSeed.hpp"
#include "pvz/SeedButton/PeashooterSeed.hpp"
#include "pvz/SeedButton/WallnutSeed.hpp"
#include "pvz/GameObject/CooldownMask.hpp"
#include "pvz/GameObject/Sun.hpp"
#include "pvz/Plant/Plant.hpp"
#include "pvz/Plant/Sunflower.hpp"
#include "pvz/Gameobject/HoldingSeed.hpp"
#include "pvz/Plant/Peashooter.hpp"
#include "pvz/Gameobject/Pea.hpp"
#include "pvz/Zombie/Zombie.hpp"
#include "pvz/Zombie/RegularZombie.hpp"
#include "pvz/Plant/Wallnut.hpp"
#include "pvz/Gameobject/Shovel.hpp"
#include "pvz/SeedButton/CherryBombSeed.hpp"
#include "pvz/Plant/CherryBomb.hpp"
#include "pvz/GameObject/Explosion.hpp"

#include "pvz/Framework/TextBase.hpp"
#include "pvz/utils.hpp"

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  /**
   * @brief Get the Sunlight object
   * 
   * @return int 
   */
  int GetSunlight() const;

  /**
   * @brief Get the Current Wave object
   * 
   * @return int 
   */
  int GetCurrentWave() const;

  /**
   * @brief Get the Tick Count object
   * 
   * @return int tickCount
   */
  int GetTickCount() const;

  /**
   * @brief Spend the given amount of sunlight.
   * 
   * @param amount The amount of sunlight to spend.
   */
  void SpendSunlight(int amount);

  /**
   * @brief Add amount of sunlight.
   * 
   * @param amount 
   */
  void AddSunlight(int amount);

  /**
   * @brief Check if the player is holding a shovel.
   * 
   * @return bool True if holding a shovel, false otherwise.
   */
  bool IsHoldingShovel() const;

  /**
   * @brief Set the Holding Shovel object.
   * 
   * @param holding 
   */
  void SetHoldingShovel(bool holding);

  /**
   * @brief Set the Holding Seed object.
   * 
   * @param seed 
   */
  void SetHoldingSeed(std::shared_ptr<HoldingSeed> seed); 

  /**
   * @brief Get the Holding Seed object.
   * 
   * @return std::shared_ptr<HoldingSeed> 
   */
  std::shared_ptr<HoldingSeed> GetHoldingSeed() const;
  
  /**
   * @brief Plant the seed.
   * 
   * @param x 
   * @param y 
   */
  void PlantSeed(int x, int y);
  
  /**
   * @brief Add a game object to the game world.
   * 
   * @param obj The game object to add.
   */
  void AddGameObject(std::shared_ptr<GameObject> obj);

  /**
   * @brief Get the Game Objects object List.
   * 
   * @return const std::list<std::shared_ptr<GameObject>>& 
   */
  const std::list<std::shared_ptr<GameObject>>& GetGameObjects() const;

  /**
   * @brief Judge whether there're zombies in this row.
   * @return true There're zombies.
   * @return false 
   */
  bool HasZombiesInRow(int y, int x) const;

private: 
  std::list<std::shared_ptr<GameObject>> gameObjects;

  /**
   * @brief Current amount of sunlight.
   */
  int sunlight;
  std::shared_ptr<TextBase> sunlightText;

  /**
   * @brief Current wave number.
   */
  int currentWave;
  std::shared_ptr<TextBase> waveText;

  /**
   * @brief Track the number of game ticks.
   */
  size_t tickCount = 0;

  /**
   * @brief The currently holding seed.
   */
  std::shared_ptr<HoldingSeed> holdingSeed;

  /**
   * @brief Whether holding a shovel.
   * 
   */
  bool holdingShovel = false;

  /**
   * @brief Create sunlight and wave number text in init().
   */
  void CreateTexts();

  /**
   * @brief Create background.
   */
  void CreateBackground();

  /**
   * @brief Create planting spots.
   */
  void CreatePlantingSpot();

  /**
   * @brief Create Seed Buttons.
   * 
   */
  void CreateSeedButtons();

  /**
   * @brief Create a Shovel object.
   */
  void CreateShovel();
  
  /**
   * @brief Create Sun.
   */
  void CreateSun();

  /**
   * @brief Create new Zombies.
   */
  void CreateZombies();

  /**
   * @brief Detect and handle collisions.
   */
  void HandleCollisions();

  /**
   * @brief Update sunlight and wave number text.
   * 
   */
  void UpdateText();



};

#endif // !GAMEWORLD_HPP__
