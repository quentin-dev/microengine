#include "GraphicsManager.hh"

#include <iostream>

namespace graphics
{

    bool GraphicsManager::setUp()
    {
        // TODO: Set these from a config file
        _window.create(sf::VideoMode(640, 480), "MicroEngine");
        _window.setFramerateLimit(60);
        _window.setVerticalSyncEnabled(true);

        return true;
    }

    void GraphicsManager::tearDown()
    {
        _window.close();
    }

    void GraphicsManager::update(engine::EventListener *eventListener)
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            eventListener->onEvent(event);
        }

    }

    void GraphicsManager::clear()
    {
        _window.clear();
    }

    void GraphicsManager::draw(gameplay::Scene &scene)
    {
        scene.draw(_window);
    }

    void GraphicsManager::display()
    {
        _window.display();
    }

} // !graphics