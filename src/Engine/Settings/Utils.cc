#include "Utils.hh"

namespace settings::utils
{
    boost::property_tree::ptree readIni(const std::string_view &pathToIni)
    {
        boost::property_tree::ptree pt;

        if (std::filesystem::exists(pathToIni))
        {
            boost::property_tree::ini_parser::read_ini(
                static_cast<std::string>(pathToIni),
                pt
            );
        }
        else
        {
            std::cerr
            << "settings::utils :: readIni :: "
            << pathToIni << " does not exist!\n";
        }

        return pt;
    }

    toml::parse_result readToml(const std::string_view &pathToToml)
    {
        toml::parse_result config;

        if (std::filesystem::exists(pathToToml))
        {
            config = toml::parse_file(pathToToml);
        }
        else
        {
            std::cerr
            << "settings::utils :: readToml :: "
            << pathToToml << " does not exist!\n";
        }

        return config;
    }

}