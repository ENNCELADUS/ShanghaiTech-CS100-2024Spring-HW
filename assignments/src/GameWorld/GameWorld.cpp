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
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
    m_gameObjects.clear();

    // YOUR CODE HERE
}

void GameWorld::Instantiate(std::shared_ptr<GameObject> newGameObject)
{
    m_gameObjects.push_back(newGameObject);
}
