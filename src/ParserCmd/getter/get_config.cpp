#include "parser_cmd.hpp"

#include <memory>


std::unique_ptr<Parsing::Config> Parsing::ParserCmd::get_config()
{
    return std::move(ParserCmd::config);
}