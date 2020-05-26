#pragma once

#include <SFML/Graphics.hpp>

#include "../EventListener.hh"

#include "../Gameplay/Scene.hh"
#include "../Settings/GraphicsSettings.hh"


namespace graphics
{

    class GraphicsManager
    {
        public:
        
            GraphicsManager() = default;
            ~GraphicsManager() = default;

            bool setUp(settings::GraphicsSettings options);
            void tearDown();

            void update(engine::EventListener *eventListener);

            void clear();
            void draw(gameplay::Scene &scene);
            void display();

        private:
            
            sf::RenderWindow _window;
    };

} // !graphics