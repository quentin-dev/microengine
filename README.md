# µEngine

A simple C++ game engine

## Goal

My goal when writing µEngine was to learn about the internal workings of a
game engine. µEngine aims mostly to be easy-to-understand. This is certainly
**not** an attempt at a performance-driven or highly-configurable game engine.

## Features

### Current

- [X] C++20 compliant
- [X] Configurable settings
- [X] Command line arguments

### Upcoming

By order of likeliness:

- [ ] Configurable levels
- [ ] Cross-platform

## Dependencies

- [SFML](https://www.sfml-dev.org/index.php)
- [Boost Property Tree](https://www.boost.org/doc/libs/1_73_0/doc/html/property_tree.html)
- [Boost Program Options](https://www.boost.org/doc/libs/1_73_0/doc/html/program_options.html)

## Usage

## Command line arguments

* `--help`: display µEngine options
* `-s [--settings-file]`: path to the `settings.ini` file - defaults to `config/settings.ini`

## Settings

The settings in `config/settings.ini` correspond to the following table:

| Section  | Name           | Type        | Default value |
|----------|----------------|-------------|---------------|
| graphics | width          | int         | 640           |
| graphics | height         | int         | 480           |
| graphics | windowName     | std::string | "MicroEngine" |
| graphics | framerateLimit | int         | 60            |
| graphics | enableVsync    | bool        | true          |
| graphics | fullscreen     | bool        | false         |

## Building

1. Install dependencies
2. Clone the repo
3. `make release` or `make debug` depending on what you want
4. `./µEngine` 

## References

A big thanks to the following:

- [Game Programming Patterns](https://gameprogrammingpatterns.com/)
- [Game Engine Architecture Vol. 3](http://dl.booktolearn.com/ebooks2/computer/gamedevelopment/9781138035454_Game_Engine_Architecture_Third_Edition_6dfa.pdf)
- [awesome-cpp](https://github.com/fffaraz/awesome-cpp)
- [awesome-modern-cpp](https://github.com/rigtorp/awesome-modern-cpp)