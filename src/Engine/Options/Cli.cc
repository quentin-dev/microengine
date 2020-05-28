#include "Cli.hh"

#include <iostream>
#include <cstdlib>

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
            "settings-file",
            boostpo::value<std::string>()->default_value(
                "config/settings.toml"
            ),
            "path to the settings file"
        )
        (
            "settings-format",
            boostpo::value<std::string>()->default_value("toml"),
            "format of the settings file"
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

    void Cli::execute()
    {
        if (vm.count("help"))
        {
            printOptions();
            std::exit(EXIT_SUCCESS);
        }
    }

    void Cli::printOptions()
    {
        std::cout << _descriptions << "\n";
    }

} // !options