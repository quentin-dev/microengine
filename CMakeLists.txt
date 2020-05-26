cmake_minimum_required(VERSION 3.13)
project(µEngine
        VERSION 0.1
        LANGUAGES CXX
        DESCRIPTION "A simple C++ game engine"
)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -pedantic -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pedantic -g3 -O0 -fsanitize=address")

if (CMAKE_BUILD_TYPE)
    message(STATUS "Build type set to " ${CMAKE_BUILD_TYPE})
endif()

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()


set(SRC
    "src/Engine/Engine.cc"
    "src/Engine/Gameplay/GameplayManager.cc"
    "src/Engine/Gameplay/Player.cc"
    "src/Engine/Gameplay/Scene.cc"
    "src/Engine/Graphics/GraphicsManager.cc"
    "src/Engine/Input/InputManager.cc"
    "src/Engine/Options/Cli.cc"
    "src/Engine/Settings/GraphicsSettings.cc"
)

set(INCLUDE
    "src/Engine"
    "src/Engine/Gameplay"
    "src/Engine/Input"
    "src/Engine/Input/Commands"
    "src/Engine/Options"
    "src/Engine/Settings"
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(Boost 1.72.0 REQUIRED COMPONENTS program_options)

set(LIBRARIES
    Boost::program_options
    sfml-graphics
    sfml-window
    sfml-system
)

add_library(microcore OBJECT)
target_sources(microcore PRIVATE ${SRC})
target_compile_options(microcore PRIVATE -Wall -Wextra)
target_include_directories(microcore PRIVATE ${INCLUDE})
target_link_libraries(microcore PRIVATE ${LIBRARIES})

add_executable(engine "src/main.cc")
target_link_libraries(engine PRIVATE microcore)
target_compile_options(engine PRIVATE -Wall -Wextra)

file(COPY config DESTINATION .)
file(COPY media DESTINATION .)

find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
    doxygen_add_docs(doxygen ${SOURCES} COMMENT "Generate html documentation")
endif()