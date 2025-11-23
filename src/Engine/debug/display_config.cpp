#include "engine.hpp"
#include "parser_cmd.hpp"
#include "iostream"

void Engine::display_config(void)
{
    
    std::cout << "FLAG="<< Engine::config->flag << "\n";
    std::cout << "Use Gpu="<< Engine::config->use_gpu << "\n";
    std::cout << "Thread="<< Engine::config->thread << "\n";
    std::cout << "End point:\n";
    //std::cout << "\tIP=" << Engine::config->end_point.ip << "\n";
    //std::cout << "\tPort=" << Engine::config->end_point.port << "\n";
}