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

### Upcoming

By order of likeliness:

- [ ] Command line arguments
- [ ] Cross-platform

## Dependencies

- [SFML](https://www.sfml-dev.org/index.php)
- [Boost Property Tree](https://www.boost.org/doc/libs/1_73_0/doc/html/property_tree.html)

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