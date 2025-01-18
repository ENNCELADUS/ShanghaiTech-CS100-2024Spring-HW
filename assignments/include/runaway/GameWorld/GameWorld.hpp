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
    virtual ~GameWorld();

    void Init() override;

    LevelStatus Update() override;

    void CleanUp() override;

    // 这些 override 并没有实际意义。而是给同学们的提示，可以使用这些函数获取输入。
    // Redundant overrides just for hinting: Use these functions for input.
    bool GetKeyDown(KeyCode key) const override { return WorldBase::GetKeyDown(key); }
    bool GetKey(KeyCode key) const override { return WorldBase::GetKey(key); }
    std::pair<int, int> GetMousePos() const override { return WorldBase::GetMousePos(); }

    void Instantiate(std::shared_ptr<GameObject> newGameObject);

    void ScrollLeft(int pixels);
    void addScore() { score++; }
    int GetScore() { return score; }

    bool CheckCollision(std::shared_ptr<GameObject> obj1, std::shared_ptr<GameObject> obj2);

private:
    std::list<std::shared_ptr<GameObject>> m_gameObjects;
    int clock = 0;
    int score = 0;
    TextBase *scoreText = nullptr;
    TextBase *resultText = nullptr;
};

#endif // !GAMEWORLD_HPP__
