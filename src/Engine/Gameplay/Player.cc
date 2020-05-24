#include "Player.hh"

namespace gameplay
{

    void Player::draw(sf::RenderWindow &window)
    {
        window.draw(_shape);
    }

    void Player::update()
    {
        _shape.setPosition(_position);
    }

    void Player::moveLeft()
    {
        _position.x -= 15.f; 
    }

    void Player::moveRight()
    {
        _position.x += 15.f;
    }

} // !gameplay