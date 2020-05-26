#include "Engine/Engine.hh"

#include "Engine/Options/Cli.hh"
#include <iostream>

namespace boostpo = boost::program_options;

int main(int argc, const char *argv[])
{
    options::Cli cli;
    cli.setUp();

    try
    {
        cli.parse(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    if (cli.vm.count("help"))
    {
        cli.printOptions();
        return 0;
    }


    engine::Engine engine;
    engine.setUp(cli.vm["settings-file"].as<std::string>());

    engine.run();
    engine.tearDown();

    return 0;
}