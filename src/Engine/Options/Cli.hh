#pragma once

#include <boost/program_options.hpp>

namespace boostpo = boost::program_options;

namespace options
{

    class Cli
    {
        public:

            Cli() = default;
            ~Cli() = default;

            void setUp();
            void parse(int argc, const char *argv[]);

            void printOptions();

            boostpo::variables_map vm;

        private:

            boostpo::options_description _descriptions{"Options"};

    };

} // !options