#include "GameplayManager.hh"

namespace gameplay
{

    bool GameplayManager::setUp()
    {
        _scenes.push_back(Scene());
        // TODO: parse from level config file
        _scenes[_currentSceneIndex].setBackground("media/img/backgroundEmpty.png");
        return true;
    }

    void GameplayManager::tearDown()
    {}

    void GameplayManager::update(const input::InputManager &input)
    {
        input::commands::Command *command = input.handleInput();
        _scenes[_currentSceneIndex].update(command);
    }

} // !gameplay