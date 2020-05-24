#include "GameplayManager.hh"

namespace gameplay
{

    bool GameplayManager::setUp()
    {
        _scenes.push_back(Scene());
        _scenes[_currentSceneIndex].setBackground("media/img/backgroundEmpty.png");
        return true;
    }

    void GameplayManager::tearDown()
    {}

    void GameplayManager::update(input::InputManager &input)
    {
        input::commands::Command *command = input.handleInput();
        _scenes[_currentSceneIndex].update(command);
    }

} // !gameplay