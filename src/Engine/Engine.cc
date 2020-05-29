#include "Engine.hh"

#include <boost/property_tree/ptree.hpp>
#include "Settings/Utils.hh"
#include "Settings/GraphicsSettings.hh"
#include "Options/Cli.hh"

namespace engine
{

    void Engine::setUp(const settings::EngineSettings &settings)
    {
        auto graphicsSettings = 
             settings::GraphicsSettings::fromFile(
                 settings.settingsFile, settings.settingsFormat
             );

        if (!settings.disableGraphics)
        {
            _graphics.setUp(graphicsSettings);
        }

        _gameplay.setUp();
        _input.setUp();
    }

    void Engine::tearDown()
    {
        _gameplay.tearDown();
        _graphics.tearDown();

    }

    void Engine::run()
    {
        _running = true;

        // sf::Clock clock;

        while(_running)
        {
            // _deltaTime = clock.restart().asSeconds();

            _graphics.update(this);
            _gameplay.update(_input);

            _graphics.clear();
            _graphics.draw(_gameplay.getCurrentScene());
            _graphics.display();
        }
    }

    void Engine::onEvent(const sf::Event &event)
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                _running = false;
                break;
            case sf::Event::KeyPressed:
                // _input.handleInput(event.key.code);
                break;
            default:
                break;
        }
    }

} // !engine