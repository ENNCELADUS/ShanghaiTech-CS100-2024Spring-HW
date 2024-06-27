#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "pvz/Framework/WorldBase.hpp"

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameObject/Background.hpp"

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
