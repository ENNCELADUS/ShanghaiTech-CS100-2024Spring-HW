#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "pvz/Framework/WorldBase.hpp"

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameObject/Background.hpp"
#include "pvz/GameObject/PlantingSpot.hpp"
#include "pvz/GameObject/SeedButton.hpp"
#include "pvz/GameObject/SunflowerSeed.hpp"
#include "pvz/GameObject/PeashooterSeed.hpp"
#include "pvz/GameObject/WallnutSeed.hpp"
#include "pvz/GameObject/CherryBombSeed.hpp"
#include "pvz/GameObject/RepeaterSeed.hpp"
#include "pvz/GameObject/CooldownMask.hpp"

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
   * @brief Getter
   * 
   * @return int 
   */
  int GetSunlight() const;
  int GetCurrentWave() const;

  /**
   * @brief Spend the given amount of sunlight.
   * 
   * @param amount The amount of sunlight to spend.
   */
  void SpendSunlight(int amount);

  /**
   * @brief Check if the player is holding a shovel.
   * 
   * @return bool True if holding a shovel, false otherwise.
   */
  bool IsHoldingShovel() const;

  /**
   * @brief Check if the player is holding a seed.
   * 
   * @return bool True if holding a seed, false otherwise.
   */
  bool IsHoldingSeed() const;
  
  /**
   * @brief Set the currently selected seed.
   * 
   * @param seed The selected seed object.
   */
  void SetSelectedSeed(std::shared_ptr<GameObject> seed);
  
  /**
   * @brief Add a game object to the game world.
   * 
   * @param obj The game object to add.
   */
  void AddGameObject(std::shared_ptr<GameObject> obj);



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
   * @brief The currently selected seed
   */
  std::shared_ptr<GameObject> selectedSeed; 


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
   * @brief Update sunlight and wave number text.
   * 
   */
  void UpdateText();



};

#endif // !GAMEWORLD_HPP__
