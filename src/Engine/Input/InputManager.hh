#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>

#include "Commands/Command.hh"

namespace input
{

    class InputManager
    {
        public:

            InputManager() = default;
            ~InputManager() = default;

            bool isKeyPressed(sf::Keyboard::Key key) const;
            commands::Command *handleInput() const;

            bool setUp();

            // TODO: Make these methods work
            void setLeftArrowCommand()
            {}

            void setRightArrowCommand()
            {}

        private:

            std::shared_ptr<commands::Command> _leftArrow = nullptr;
            std::shared_ptr<commands::Command> _rightArrow = nullptr;
    };

} // !input