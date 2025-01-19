#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>
#include "runaway/Framework/WorldBase.hpp"
#include "runaway/Framework/TextBase.hpp"
#include "runaway/GameObject/GameObject.hpp"
#include "runaway/utils.hpp"

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
public:
    GameWorld();
    ~GameWorld() override;

    void Init() override;
    LevelStatus Update() override;
    void CleanUp() override;

    void Instantiate(std::shared_ptr<GameObject> newGameObject);
    void AddScore(int points);
    int GetScore() const { return m_score; }

    bool CheckCollision(const std::shared_ptr<GameObject> &obj1, const std::shared_ptr<GameObject> &obj2) const;

private:
    void HandleCollisions();
    void UpdateScore();
    void RemoveDeadObjects();
    bool IsPlayerDead() const;
    void CreateGoblin();

    std::list<std::shared_ptr<GameObject>> m_gameObjects;
    int m_clock;
    int m_score;
    std::unique_ptr<TextBase> m_scoreText;
    std::unique_ptr<TextBase> m_resultText;

    static constexpr int GOBLIN_SPAWN_INTERVAL = 240;
    static constexpr int GOBLIN_KILL_SCORE = 20;
};

#endif // GAMEWORLD_HPP__