#include "Engine/Engine.hh"

#include <boost/program_options.hpp>
#include <iostream>

namespace boostpo = boost::program_options;

int main(int argc, const char *argv[])
{
    boostpo::options_description options_descriptions{"Options"};

    options_descriptions.add_options()
        (
            "help",
            "display µEngine options"
        )
        (
            "settings-file,s",
            boostpo::value<std::string>()->default_value("config/settings.ini"),
            "Path to settings.ini"
        );

    boostpo::variables_map vm;

    try
    {
        boostpo::store(
            boostpo::parse_command_line(argc, argv, options_descriptions),
            vm
        );
        boostpo::notify(vm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    if (vm.count("help"))
    {
        std::cout << options_descriptions << "\n";
        return 0;
    }


    engine::Engine engine;
    engine.setUp(vm["settings-file"].as<std::string>());

    engine.run();
    engine.tearDown();

    return 0;
}