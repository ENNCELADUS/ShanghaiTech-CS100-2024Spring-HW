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
    score = 0;
    clock = 0;

    Instantiate(std::make_shared<Background>(shared_from_this()));

    // Create the player at position (200, 120)
    std::shared_ptr<Player> player = std::make_shared<Player>(shared_from_this());

    // Add the player to the game world (instantiate the player object)
    Instantiate(player);

    // Create the score display using the TextBase class
    scoreText = new TextBase(WINDOW_WIDTH - 160, 8, "Score: 0", 1.0, 1.0, 1.0, false);
}

LevelStatus GameWorld::Update()
{
    // Increment the clock to track the passage of time (ticks)
    clock++;

    // Every 240 ticks, create a new Goblin at (WINDOW_WIDTH-1, 120)
    if (clock >= 240)
    {
        // Create a new Goblin at position (WINDOW_WIDTH-1, 120)
        std::shared_ptr<Goblin> newGoblin = std::make_shared<Goblin>(WINDOW_WIDTH - 1, 120, shared_from_this());

        // Add the new Goblin to the game world
        Instantiate(newGoblin);

        // Reset clock after creating a goblin
        clock = 0;
    }

    for (auto &gameObject : m_gameObjects)
    {
        gameObject->Update();
    }

    // Iterate through all game objects
    for (auto &obj : m_gameObjects)
    {
        // Check for collision between projectiles (Bullets or Axes) and other objects
        if (obj->GetType() == GameObject::Type::ProjectilePlayer)
        {
            for (auto &other : m_gameObjects)
            {
                if (obj == other)
                    continue; // Skip self-collision

                if (obj->GetType() == GameObject::Type::ProjectilePlayer && other->GetType() == GameObject::Type::Enemy)
                {

                    if (CheckCollision(obj, other))
                    {
                        obj->OnCollision(other); // Call OnCollision for the bullet
                        other->OnCollision(obj); // Call OnCollision for the Goblin
                    }
                }
            }
        }

        // Handle Axe collisions (Axe is also a projectile)
        if (obj->GetType() == GameObject::Type::ProjectileEnemy)
        {
            for (auto &other : m_gameObjects)
            {
                if (obj == other)
                    continue; // Skip self-collision

                if (obj->GetType() == GameObject::Type::ProjectileEnemy && other->GetType() == GameObject::Type::Player)
                {
                    if (CheckCollision(obj, other))
                    {
                        obj->OnCollision(other); // Call OnCollision for the axe
                        other->OnCollision(obj); // Call OnCollision for the player
                    }
                }
            }
        }

        // Handle Goblin vs Player collisions
        if (obj->GetType() == GameObject::Type::Enemy)
        {
            for (auto &other : m_gameObjects)
            {
                if (obj == other)
                    continue; // Skip self-collision

                if (obj->GetType() == GameObject::Type::Enemy && other->GetType() == GameObject::Type::Player)
                {
                    if (CheckCollision(obj, other))
                    {
                        obj->OnCollision(other); // Call OnCollision for the goblin
                        other->OnCollision(obj); // Call OnCollision for the player
                    }
                }
            }
        }
    }

    // Update the score by check whether a Goblin is dead
    for (auto &obj : m_gameObjects)
    {
        if (obj->GetType() == GameObject::Type::Enemy && !obj->IsAlive())
        {
            score += 20;
        }
    }

    // Check if the player is dead
    for (auto &obj : m_gameObjects)
    {
        if (obj->GetType() == GameObject::Type::Player && obj->GetHP() <= 0)
        {
            resultText = new TextBase(348, 50, std::to_string(score), 1.0, 1.0, 1.0, false);
            return LevelStatus::LOSING;
        }
    }

    // Remove dead objects from the game world
    m_gameObjects.remove_if([](const auto &obj)
                            { return !obj->IsAlive(); });

    // Update score display if scoreText exists
    if (scoreText)
    {
        scoreText->SetText("Score: " + std::to_string(score));
    }

    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
    m_gameObjects.clear();
    if (scoreText != nullptr)
    {
        delete scoreText;
        scoreText = nullptr; // Set to nullptr after deletion to avoid dangling pointer
    }
    if (resultText != nullptr)
    {
        delete resultText;
        resultText = nullptr; // Set to nullptr after deletion to avoid dangling pointer
    }
}

void GameWorld::Instantiate(std::shared_ptr<GameObject> newGameObject)
{
    m_gameObjects.push_back(newGameObject);
}

// Collision Detection Helper Function
bool GameWorld::CheckCollision(std::shared_ptr<GameObject> obj1, std::shared_ptr<GameObject> obj2)
{
    int dx = abs(obj1->GetX() - obj2->GetX());
    int dy = abs(obj1->GetY() - obj2->GetY());
    int combinedWidth = (obj1->GetWidth() + obj2->GetWidth()) / 2;
    int combinedHeight = (obj1->GetHeight() + obj2->GetHeight()) / 2;

    // Check if the two objects overlap in both the x and y axes
    return (dx < combinedWidth) && (dy < combinedHeight);
}