#include "InputManager.hh"

#include "Commands/MoveLeftCommand.hh"
#include "Commands/MoveRightCommand.hh"

namespace input
{

    bool InputManager::setUp()
    {
        
        _leftArrow = std::make_shared<commands::MoveLeftCommand>();
        _rightArrow = std::make_shared<commands::MoveRightCommand>();

        return true;
    }

    bool InputManager::isKeyPressed(sf::Keyboard::Key key) const
    {
        return sf::Keyboard::isKeyPressed(key);
    }

    commands::Command *InputManager::handleInput() const
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            return _leftArrow.get();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            return _rightArrow.get();
        }
        
        return nullptr;
    }

} // !input