#include "engine.hpp"
#include "parser_cmd.hpp"

void Engine::set_config(std::unique_ptr<Parsing::Config> config)
{
    Engine::config = std::move(config);
}