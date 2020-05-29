#include "Engine/Engine.hh"

#include "Engine/Options/Cli.hh"
#include <iostream>
#include "Engine/Settings/EngineSettings.hh"

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

    cli.execute();

    settings::EngineSettings settings;

    settings.settingsFile = cli.vm["settings-file"].as<const std::string>();
    settings.settingsFormat = cli.vm["settings-format"].as<const std::string>();
    settings.disableGraphics = cli.vm["disable-graphics"].as<bool>();

    engine::Engine engine;

    engine.setUp(settings);

    if (!cli.vm["dry-run"].as<bool>())
    {
        engine.run();
    }

    engine.tearDown();

    return 0;
}