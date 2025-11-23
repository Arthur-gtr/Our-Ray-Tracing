#include <iostream>
#include "engine.hpp"
#include "parser_cmd.hpp"

/*IL FAUT ABSOLUMENT UNE BAR DE CHARGEMENT QUAND ON ECRIS UNE IMAGE SANS GUI*/




int main(int ac, char **av)
{
    if (ac == 1){
        std::cerr << "Ray_tracer [scene][FLAG]" << std::endl;
        return EXIT_FAILURE;
    }
    Parsing::ParserCmd parse_cmd(ac, av);/*PARSE FLAG Pourrais etre le constructeur*/
    if (parse_cmd.get_error() == -1){
        std::cerr << "Parsing flag error" << std::endl;
        return EXIT_FAILURE;
    }
    Engine engine(parse_cmd.get_config(), av[1]);
    return EXIT_SUCCESS;
}