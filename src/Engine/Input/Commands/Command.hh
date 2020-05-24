#pragma once

#include "../../Gameplay/Player.hh"

namespace input::commands
{

    class Command
    {
        public:
            
            virtual ~Command() {}
            virtual void execute(gameplay::Player &player) = 0;
    };

} // !input::commands