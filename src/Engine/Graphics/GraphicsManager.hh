#pragma once

#include <SFML/Graphics.hpp>

#include "../EventListener.hh"

#include "../Gameplay/Scene.hh"

namespace graphics
{

    class GraphicsManager
    {
        public:
        
            GraphicsManager() = default;
            ~GraphicsManager() = default;

            bool setUp();
            void tearDown();

            void update(engine::EventListener *eventListener);

            void clear();
            void draw(gameplay::Scene &scene);
            void display();

        private:
            
            sf::RenderWindow _window;
    };

} // !graphics