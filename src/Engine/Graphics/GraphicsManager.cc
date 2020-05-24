#include "GraphicsManager.hh"

#include <iostream>

#include "../Options/GraphicsOptions.hh"

namespace graphics
{

    bool GraphicsManager::setUp(options::GraphicsOptions options)
    {
        _window.create(
            sf::VideoMode(options.getWidth(), options.getHeight()),
            options.getWindowName(),
            options.getWindowStyle()
        );
        _window.setFramerateLimit(options.getFramerateLimit());
        _window.setVerticalSyncEnabled(options.getEnableVsync());

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