#include "parser_cmd.hpp"
#include <memory>


std::unique_ptr<Parsing::config_t> Parsing::ParserCmd::get_config()
{
    return std::move(config);
}