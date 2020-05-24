#pragma once

#include "Command.hh"

namespace input::commands
{

    class MoveRightCommand: public Command
    {
        public:

            MoveRightCommand() = default;
            ~MoveRightCommand() = default;

            void execute(gameplay::Player &player) override final
            {
                player.moveRight();
            }
    };

} // !input::commands