#pragma once

#include <boost/property_tree/ptree.hpp>
#include <SFML/Window.hpp>

namespace options
{

    class GraphicsOptions
    {
        public:

            GraphicsOptions() = default;
            ~GraphicsOptions() = default;

            static GraphicsOptions fromIni(boost::property_tree::ptree &pt);

            int getWidth()
            {
                return _width;
            }

            int getHeight()
            {
                return _height;
            }

            std::string getWindowName()
            {
                return _windowName;
            }

            int getFramerateLimit()
            {
                return _framerateLimit;
            }

            bool getEnableVsync()
            {
                return _enableVsync;
            }

            sf::Uint32 getWindowStyle()
            {
                if (_fullscreen)
                {
                    return sf::Style::Fullscreen;
                }

                return sf::Style::Default;
            }


        private:

            int _width = 640;
            int _height = 480;

            std::string _windowName = "MicroEngine";

            int _framerateLimit = 60;
            bool _enableVsync = true;

            bool _fullscreen = false;

    };

} // !options