#include "runaway/GameWorld/GameWorld.hpp"

#include "runaway/Framework/TextBase.hpp"
#include "runaway/GameObject/Background.hpp"
#include "runaway/GameObject/Player.hpp"
#include "runaway/GameObject/Enemies.hpp"
#include "runaway/GameObject/Projectiles.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
    // 初始化背景
    Instantiate(std::make_shared<Background>(shared_from_this()));

    // 创建文本显示，显示分数（推荐显示位置：WINDOW_WIDTH - 160, 8）
    scoreText = new TextBase(shared_from_this(), "Score: 0", WINDOW_WIDTH - 160, 8);
    Instantiate(std::shared_ptr<GameObject>(scoreText));

    // 初始化其他关卡数据
    score = 0;
    clock = 0;

    // 创建玩家对象
    Instantiate(std::make_shared<Player>(shared_from_this(), 200, 120));
}

LevelStatus GameWorld::Update()
{
    // 生成新的哥布林，每 240 ticks
    clock++;
    if (clock % 240 == 0)
    {
        Instantiate(std::make_shared<Goblin>(shared_from_this(), WINDOW_WIDTH - 1, 120));
    }

    // 遍历所有游戏对象并更新
    for (auto &gameObject : m_gameObjects)
    {
        gameObject->Update();
    }

    // 检测碰撞
    for (auto &gameObject : m_gameObjects)
    {
        // 示例：检查子弹与哥布林的碰撞
        if (auto bullet = std::dynamic_pointer_cast<Bullet>(gameObject))
        {
            for (auto &goblin : m_gameObjects)
            {
                if (auto g = std::dynamic_pointer_cast<Goblin>(goblin))
                {
                    if (bullet->CollidesWith(g))
                    {
                        // 处理碰撞
                        g->Die();
                        bullet->Die();
                    }
                }
            }
        }
        // 其他碰撞检测：斧头打到玩家，哥布林碰到玩家等
    }

    // 遍历并删除所有标记为死亡的对象
    m_gameObjects.remove_if([](const std::shared_ptr<GameObject> &gameObject)
                            { return gameObject->IsDead(); });

    // 判断玩家是否死亡
    if (auto player = std::dynamic_pointer_cast<Player>(m_gameObjects.front()))
    {
        if (player->IsDead())
        {
            // 显示失败界面
            scoreText->SetText("Game Over! Score: " + std::to_string(score));
            return LevelStatus::LOSING;
        }
    }

    // 更新文本显示
    scoreText->SetText("Score: " + std::to_string(score));

    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
    m_gameObjects.clear();
    if (scoreText)
    {
        delete scoreText;
        scoreText = nullptr;
    }
}

void GameWorld::Instantiate(std::shared_ptr<GameObject> newGameObject)
{
    m_gameObjects.push_back(newGameObject);
}