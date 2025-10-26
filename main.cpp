#include <iostream>
#include "engine.hpp"

/*IL FAUT ABSOLUMENT UNE BAR DE CHARGEMENT QUAND ON ECRIS UNE IMAGE SANS GUI*/

bool Engine::parse_flag(int ac, char **av)
{
    //FILL_uint32 engine.flag vérifier la cohérence des arguments dérrière les flags
    //vérifier la coherence entre les flags c'est a dire si le mode gpu est actif ne pas avoir le multi threads
    /*retrun false || true*/
}


int main(int ac, char **av)
{
    if (ac == 1)
        return EXIT_FAILURE;
    Engine my_engine;
    std::cout << "parssing..." << std::endl;
    my_engine.parse_flag(ac, av);
    std::cout << "parssing end" << std::endl;
    return EXIT_SUCCESS;
}