#pragma once

#include <string_view>

namespace settings
{
    class EngineSettings
    {
        public:

            EngineSettings() = default;
            ~EngineSettings() = default;

            std::string_view settingsFile;
            std::string_view settingsFormat;
            bool disableGraphics;

        private:

    };
}