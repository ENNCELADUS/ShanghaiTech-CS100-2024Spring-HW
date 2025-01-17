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
    // Initialize the background
    Instantiate(std::make_shared<Background>(shared_from_this()));

    // Create text display for the score (recommended position: WINDOW_WIDTH - 160, 8)
    scoreText = new TextBase("Score: 0", WINDOW_WIDTH - 160, 8, shared_from_this());
    Instantiate(std::shared_ptr<GameObject>(scoreText));

    // Initialize other level data
    score = 0;
    clock = 0;

    // Create the player object at position (200, 120)
    Instantiate(std::make_shared<Player>(shared_from_this(), 200, 120));
}

LevelStatus GameWorld::Update()
{
    // Generate a new Goblin every 240 ticks
    clock++;
    if (clock % 240 == 0)
    {
        Instantiate(std::make_shared<Goblin>(shared_from_this(), WINDOW_WIDTH - 1, 120));
    }

    // Iterate through all game objects and update them
    for (auto &gameObject : m_gameObjects)
    {
        gameObject->Update();
    }

    // Check for collisions
    for (auto &gameObject : m_gameObjects)
    {
        // Example: Check if a Bullet collides with a Goblin
        if (auto bullet = std::dynamic_pointer_cast<Bullet>(gameObject))
        {
            for (auto &goblin : m_gameObjects)
            {
                if (auto g = std::dynamic_pointer_cast<Goblin>(goblin))
                {
                    if (bullet->CollidesWith(g))
                    {
                        // Handle the collision (e.g., destroy the Goblin and Bullet)
                        g->Die();
                        bullet->Die();
                    }
                }
            }
        }
        // Additional collision checks can be added here, e.g., Axe hitting Player, Goblin touching Player
    }

    // Iterate through and remove any game objects marked as "dead"
    m_gameObjects.remove_if([](const std::shared_ptr<GameObject> &gameObject)
                            { return !gameObject->IsAlive(); });

    // Check if the player has died
    if (auto player = std::dynamic_pointer_cast<Player>(m_gameObjects.front()))
    {
        if (player->IsDead())
        {
            // If player is dead, show the "Game Over" screen with score
            scoreText->SetText("Game Over! Score: " + std::to_string(score));
            return LevelStatus::LOSING;
        }
    }

    // Update the score display
    scoreText->SetText("Score: " + std::to_string(score));

    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
    // Clear all game objects from the world
    m_gameObjects.clear();

    // Delete the score text object to free up resources
    if (scoreText)
    {
        delete scoreText;
        scoreText = nullptr;
    }
}

void GameWorld::Instantiate(std::shared_ptr<GameObject> newGameObject)
{
    // Add the new game object to the list of game objects
    m_gameObjects.push_back(newGameObject);
}
