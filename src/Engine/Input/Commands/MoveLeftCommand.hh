#pragma once

#include "Command.hh"

namespace input::commands
{

    class MoveLeftCommand: public Command
    {

        public:

            MoveLeftCommand() = default;
            ~MoveLeftCommand() = default;

            void execute(gameplay::Player &player) override final
            {
                player.moveLeft();
            }
    };

} // !input::commands