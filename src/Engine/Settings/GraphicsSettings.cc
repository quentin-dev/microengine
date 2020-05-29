#include "GraphicsSettings.hh"

#include <iostream>
#include "../Options/Cli.hh"
#include "Utils.hh"

namespace settings
{
    GraphicsSettings GraphicsSettings::fromFile(
        const std::string_view &settingsFile,
        const std::string_view &settingsFormat)
    {
        if (settingsFormat.compare(options::Cli::INI) == 0)
        {
            auto pt = utils::readIni(settingsFile);
            return fromIni(pt);
        }
        else if (settingsFormat.compare(options::Cli::TOML) == 0)
        {
            auto config = utils::readToml(settingsFile);
            return fromToml(config);
        }

        std::cerr
        << "GraphicsSettings :: fromFile :: "
        << settingsFormat << " format not recognized\n"
        << "GraphicsSettings :: fromFile :: Falling back to default settings\n";

        return GraphicsSettings();
    }

    GraphicsSettings GraphicsSettings::fromIni(boost::property_tree::ptree &pt)
    {
        GraphicsSettings settings;

        try
        {
            settings._width = pt.get<int>("graphics.width");
            settings._height = pt.get<int>("graphics.height");

            settings._windowName = pt.get<std::string>("graphics.windowName");
            
            settings._framerateLimit = pt.get<int>("graphics.framerateLimit");
            settings._enableVsync = pt.get<bool>("graphics.enableVsync");

            settings._fullscreen = pt.get<bool>("graphics.fullscreen");
        } 
        catch (const std::exception&)
        {
            std::cerr
            << "GraphicsSettings :: fromIni :: Could not parse settings file\n"
            << "GraphicsSettings :: fromIni :: Falling back to default\n";

            return GraphicsSettings();
        }

        return settings;
    }

    GraphicsSettings GraphicsSettings::fromToml(toml::parse_result &config)
    {
        GraphicsSettings settings;

        try
        {

            // TODO: Fix partial parsing, check if default ?

            settings._width =
                config["graphics"]["width"].value_or(settings._width);
            
            settings._height =
                config["graphics"]["height"].value_or(settings._height);

            settings._windowName =
                config["graphics"]["windowName"].value_or(settings._windowName);

            settings._framerateLimit =
                config["graphics"]["framerateLimit"].value_or(
                    settings._framerateLimit
                );
            
            settings._enableVsync =
                config["graphics"]["enableVsync"].value_or(
                    settings._enableVsync
                );
            
            settings._fullscreen =
                config["graphics"]["fullscreen"].value_or(settings._fullscreen);
        }
        catch (const std::exception&)
        {
            std::cerr
            << "GraphicsSettings :: fromToml :: Could not parse settings file\n"
            << "GraphicsSettings :: fromToml :: Falling back to default\n";

            return GraphicsSettings();
        }

        return settings;
    }

} // !settings