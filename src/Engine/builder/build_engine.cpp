#include "engine.hpp"


Engine::Engine(std::unique_ptr<Parsing::Config> config, char *path)
{
    std::cout << "parssing..." << std::endl;
    Engine::set_config(std::move(config));
    Engine::display_config();
    //Engine::parse_scene(char *path);
    //FILL_uint32 engine.flag vérifier la cohérence des arguments dérrière les flags
    //vérifier la coherence entre les flags c'est a dire si le mode gpu est actif ne pas avoir le multi threads
    /*retrun false || true*/
    std::cout << "parssing end" << std::endl;
}