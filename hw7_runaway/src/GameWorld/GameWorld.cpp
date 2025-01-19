#include "runaway/GameWorld/GameWorld.hpp"
#include "runaway/GameObject/Background.hpp"
#include "runaway/GameObject/Player.hpp"
#include "runaway/GameObject/Enemies.hpp"

GameWorld::GameWorld() : m_clock(0), m_score(0) {}

GameWorld::~GameWorld() = default;

void GameWorld::Init()
{
    Instantiate(std::make_shared<Background>(shared_from_this()));
    Instantiate(std::make_shared<Player>(shared_from_this()));
    m_scoreText = std::make_unique<TextBase>(WINDOW_WIDTH - 160, 8, "Score: 0", 1.0, 1.0, 1.0, false);
}

LevelStatus GameWorld::Update()
{
    m_clock++;

    if (m_clock >= GOBLIN_SPAWN_INTERVAL)
    {
        CreateGoblin();
        m_clock = 0;
    }

    for (auto &gameObject : m_gameObjects)
    {
        gameObject->Update();
    }

    HandleCollisions();
    UpdateScore();

    if (IsPlayerDead())
    {
        m_resultText = std::make_unique<TextBase>(346, 50, std::to_string(m_score), 1.0, 1.0, 1.0, false);
        return LevelStatus::LOSING;
    }

    RemoveDeadObjects();

    m_scoreText->SetText("Score: " + std::to_string(m_score));
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
    m_gameObjects.clear();
    m_scoreText.reset();
    m_resultText.reset();
}

void GameWorld::Instantiate(std::shared_ptr<GameObject> newGameObject)
{
    m_gameObjects.push_back(std::move(newGameObject));
}

void GameWorld::AddScore(int points)
{
    m_score += points;
}

bool GameWorld::CheckCollision(const std::shared_ptr<GameObject> &obj1, const std::shared_ptr<GameObject> &obj2) const
{
    int dx = abs(obj1->GetX() - obj2->GetX());
    int dy = abs(obj1->GetY() - obj2->GetY());
    int combinedWidth = (obj1->GetWidth() + obj2->GetWidth()) / 2;
    int combinedHeight = (obj1->GetHeight() + obj2->GetHeight()) / 2;

    return (dx < combinedWidth) && (dy < combinedHeight);
}

void GameWorld::HandleCollisions()
{
    for (auto &obj : m_gameObjects)
    {
        if (obj->GetType() == GameObject::Type::ProjectilePlayer ||
            obj->GetType() == GameObject::Type::ProjectileEnemy ||
            obj->GetType() == GameObject::Type::Enemy)
        {
            for (auto &other : m_gameObjects)
            {
                if (obj == other)
                    continue;

                if ((obj->GetType() == GameObject::Type::ProjectilePlayer && other->GetType() == GameObject::Type::Enemy) ||
                    (obj->GetType() == GameObject::Type::ProjectileEnemy && other->GetType() == GameObject::Type::Player) ||
                    (obj->GetType() == GameObject::Type::Enemy && other->GetType() == GameObject::Type::Player))
                {
                    if (CheckCollision(obj, other))
                    {
                        obj->OnCollision(other);
                        other->OnCollision(obj);
                    }
                }
            }
        }
    }
}

void GameWorld::UpdateScore()
{
    for (auto &obj : m_gameObjects)
    {
        if (obj->GetType() == GameObject::Type::Enemy && !obj->IsAlive())
        {
            AddScore(GOBLIN_KILL_SCORE);
        }
    }
}

void GameWorld::RemoveDeadObjects()
{
    m_gameObjects.remove_if([](const auto &obj)
                            { return !obj->IsAlive(); });
}

bool GameWorld::IsPlayerDead() const
{
    for (auto &obj : m_gameObjects)
    {
        if (obj->GetType() == GameObject::Type::Player && obj->GetHP() <= 0)
        {
            return true;
        }
    }
    return false;
}

void GameWorld::CreateGoblin()
{
    Instantiate(std::make_shared<Goblin>(WINDOW_WIDTH - 1, 120, shared_from_this()));
}