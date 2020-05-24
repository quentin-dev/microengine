#include "Scene.hh"

namespace gameplay
{
    void Scene::setBackground(std::string bgPath)
    {
        _bgTexture.loadFromFile(bgPath);
        _bgSprite.setTexture(_bgTexture);
    }

    void Scene::draw(sf::RenderWindow &window)
    {
        window.draw(_bgSprite);
        _player.draw(window);
    }

    void Scene::update(input::commands::Command *command)
    {
        if (command)
        {
            command->execute(_player);
        }

        _player.update();
    }
}