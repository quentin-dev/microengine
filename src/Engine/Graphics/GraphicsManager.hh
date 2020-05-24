#pragma once

#include <SFML/Graphics.hpp>

#include "../EventListener.hh"

#include "../Gameplay/Scene.hh"
#include "../Options/GraphicsOptions.hh"


namespace graphics
{

    class GraphicsManager
    {
        public:
        
            GraphicsManager() = default;
            ~GraphicsManager() = default;

            bool setUp(options::GraphicsOptions options);
            void tearDown();

            void update(engine::EventListener *eventListener);

            void clear();
            void draw(gameplay::Scene &scene);
            void display();

        private:
            
            sf::RenderWindow _window;
    };

} // !graphics