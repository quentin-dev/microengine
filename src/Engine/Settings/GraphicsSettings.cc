#include "GraphicsSettings.hh"

#include <iostream>

namespace settings
{

    GraphicsSettings GraphicsSettings::fromIni(boost::property_tree::ptree &pt)
    {
        try
        {
            GraphicsSettings settings;

            settings._width = pt.get<int>("graphics.width");
            settings._height = pt.get<int>("graphics.height");

            settings._windowName = pt.get<std::string>("graphics.windowName");
            
            settings._framerateLimit = pt.get<int>("graphics.framerateLimit");
            settings._enableVsync = pt.get<bool>("graphics.enableVsync");

            settings._fullscreen = pt.get<bool>("graphics.fullscreen");

            return settings;
        } 
        catch (const std::exception&)
        {
            std::cerr
            << "GraphicsSettings :: fromIni :: Could not parse settings file\n"
            << "GraphicsSettings :: fromIni :: Falling back to default\n";

            return GraphicsSettings();
        }
    }

} // !settings