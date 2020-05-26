#include "GraphicsOptions.hh"

#include <iostream>

namespace options
{

    GraphicsOptions GraphicsOptions::fromIni(boost::property_tree::ptree &pt)
    {
        try
        {
            GraphicsOptions options;

            options._width = pt.get<int>("graphics.width");
            options._height = pt.get<int>("graphics.height");

            options._windowName = pt.get<std::string>("graphics.windowName");
            
            options._framerateLimit = pt.get<int>("graphics.framerateLimit");
            options._enableVsync = pt.get<bool>("graphics.enableVsync");

            options._fullscreen = pt.get<bool>("graphics.fullscreen");

            return options;
        } 
        catch (const std::exception&)
        {
            std::cerr
            << "GraphicsOptions :: fromIni :: Could not parse settings.ini\n"
            << "GraphicsOptions :: fromIni :: Falling back to default\n";

            return GraphicsOptions();
        }
    }

} // !options