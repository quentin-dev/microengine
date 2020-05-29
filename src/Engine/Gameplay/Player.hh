#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

namespace gameplay
{

    class Player
    {
        public:

            Player()
                : _position{300.f, 50.f}
                , _shape{30.f}
            {
                // _position = sf::Vector2f{ 300.f, 50.f };

                // _shape = sf::CircleShape(30.f);
                _shape.setFillColor(sf::Color::Green);
                _shape.setPosition(_position);
            }

            ~Player() = default;

            void draw(sf::RenderWindow &window);
            void update();

            // TODO: Make coherent with a grid / scene
            void moveLeft();
            void moveRight();

            sf::Vector2f getPosition()
            { 
                return _position;
            }

        private:

            sf::Vector2f _position;
            sf::CircleShape _shape;

    };

} // !gameplay