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
    // YOUR CODE HERE
}

LevelStatus GameWorld::Update()
{
    // YOUR CODE HERE

    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
    // YOUR CODE HERE
}

void GameWorld::Instantiate(std::shared_ptr<GameObject> newGameObject)
{
    m_gameObjects.push_back(newGameObject);
}
