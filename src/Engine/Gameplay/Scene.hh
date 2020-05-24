#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "Player.hh"
#include "../Input/Commands/Command.hh"

namespace gameplay
{
    class Scene
    {
        public:

            Scene() = default;
            ~Scene() = default;

            void setBackground(std::string bgPath);

            void draw(sf::RenderWindow &window);
            void update(input::commands::Command *command);

        private:

            gameplay::Player _player;

            sf::Texture _bgTexture;
            sf::Sprite _bgSprite;            
    };

} // !gameplay