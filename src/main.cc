#include "Engine/Engine.hh"

// #include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <iostream>

int main(void)
{
    // TODO: Read CLI arguments
    engine::Engine engine;
    engine.setUp("settings.ini");

    engine.run();
    engine.tearDown();

    return 0;
}