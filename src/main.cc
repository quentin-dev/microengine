#include "Engine/Engine.hh"

int main(void)
{
    // TODO: Read CLI arguments
    engine::Engine engine;
    engine.setUp();

    engine.run();
    engine.tearDown();

    return 0;
}