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
    Instantiate(std::make_shared<Background>(shared_from_this()));

    // Create the player at position (200, 120)
    std::shared_ptr<Player> player = std::make_shared<Player>(shared_from_this());

    // Add the player to the game world (instantiate the player object)
    Instantiate(player);
}

LevelStatus GameWorld::Update()
{
    for (auto &gameObject : m_gameObjects)
    {
        gameObject->Update();
    }

    // YOUR CODE HERE

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
