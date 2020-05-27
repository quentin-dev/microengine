#pragma once

#include <boost/property_tree/ini_parser.hpp>
#include <filesystem>
#include <iostream>
#include "../external/toml.hpp"
#include <fstream>

namespace settings::utils
{
    boost::property_tree::ptree readIni(const std::string &pathToIni);

    toml::parse_result readToml(const std::string &pathToToml);
}