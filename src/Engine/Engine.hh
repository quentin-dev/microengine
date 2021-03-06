#pragma once

#include "EventListener.hh"
#include "Graphics/GraphicsManager.hh"
#include "Input/InputManager.hh"
#include "Gameplay/GameplayManager.hh"
#include "Settings/EngineSettings.hh"

namespace engine
{
    class Engine : public EventListener
    {
        public:

            Engine() = default;
            ~Engine() = default;

            void setUp(const settings::EngineSettings &settings);
            void tearDown();

            void run();

            void onEvent(const sf::Event &event) override;

        private:

            bool _running = false;

            // TODO: use for frame-independent updates
            // float _deltaTime;

            graphics::GraphicsManager _graphics;
            input::InputManager _input;
            gameplay::GameplayManager _gameplay;
    };
} // !engine