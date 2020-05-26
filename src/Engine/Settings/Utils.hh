#pragma once

#include <boost/property_tree/ini_parser.hpp>
#include <filesystem>
#include <iostream>

namespace settings::utils
{
    boost::property_tree::ptree readIni(std::string pathToIni)
    {
        boost::property_tree::ptree pt;

        if (std::filesystem::exists(pathToIni))
        {
            boost::property_tree::ini_parser::read_ini(pathToIni, pt);
        }
        else
        {
            std::cerr
            << "settings::utils :: readIni :: "
            << pathToIni << " does not exist!\n";
        }

        return pt;
    }

}