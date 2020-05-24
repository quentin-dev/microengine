#pragma once

#include <SFML/Window/Event.hpp>

namespace engine
{
    class EventListener
    {
        public:

            virtual void onEvent(const sf::Event &event) = 0;
    };
} // !engine