#include "engine.hpp"


Engine::Engine(std::unique_ptr<Parsing::config_t> config)
{
    std::cout << "parssing..." << std::endl;
    Engine::set_config(std::move(config));
    //FILL_uint32 engine.flag vérifier la cohérence des arguments dérrière les flags
    //vérifier la coherence entre les flags c'est a dire si le mode gpu est actif ne pas avoir le multi threads
    /*retrun false || true*/
    std::cout << "parssing end" << std::endl;
}