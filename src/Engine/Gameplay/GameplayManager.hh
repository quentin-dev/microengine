#pragma once

#include <vector>

#include "Scene.hh"
#include "../Input/InputManager.hh"

namespace gameplay
{

    class GameplayManager
    {
        public:

            GameplayManager() = default;
            ~GameplayManager() = default;

            bool setUp();
            void tearDown();

            void update(const input::InputManager &input);

            Scene& getCurrentScene()
            {
                return _scenes[_currentSceneIndex];
            }

        private:

            int _currentSceneIndex = 0;
            std::vector<Scene> _scenes;
    };

} // !gameplay