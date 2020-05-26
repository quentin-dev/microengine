#include "Cli.hh"

#include <iostream>

namespace options
{

    void Cli::setUp()
    {
        _descriptions.add_options()
        (
            "help",
            "display µEngine options"
        )
        (
            "settings-file,s",
            boostpo::value<std::string>()->default_value("config/settings.ini"),
            "Path to settings.ini"
        );
    }

    void Cli::parse(int argc, const char *argv[])
    {
        boostpo::store(
            boostpo::parse_command_line(argc, argv, _descriptions),
            vm
        );
        boostpo::notify(vm);
    }

    void Cli::printOptions()
    {
        std::cout << _descriptions << "\n";
    }

} // !options