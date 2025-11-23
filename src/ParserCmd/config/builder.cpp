#include "parser_cmd.hpp"

Parsing::Config::Config(void)
{
    Config::end_point;
    Config::flag = 0;
    Config::thread = 0;
    Config::use_gpu = false;
}