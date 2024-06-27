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
   * @brief Update sunlight and wave number text.
   * 
   */
  void UpdateText();
  
  void CreateBackground();
  // void CreatePlantSlots();
  // void CreateSeedButtons();
  // void CreateShovelButton();
};

#endif // !GAMEWORLD_HPP__
