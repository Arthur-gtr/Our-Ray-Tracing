#include <cstring>

#include "parser_cmd.hpp"

/*renvoie -1 en cas d'erreur*/
int Parsing::ParserCmd::find_long_flag(char *flag)
{
    flag += 2;

    for (size_t i = 0; i < SIZE_TAB; i++){
        if (strcmp(FLAG_TAB[i].long_flag, flag) == 0){
            ParserCmd::config->flag |= FLAG_TAB[i].flag_value;
            ParserCmd::flag_fill = i;
            return FLAG_TAB[i].arguments;
        }
    }
    ParserCmd::error = -1;
    return -1;
}

/*renvoie -1 en cas d'erreur*/
int Parsing::ParserCmd::find_short_flag(char flag)
{
    for (size_t i = 0; i < SIZE_TAB; i++){
        if (FLAG_TAB[i].short_flag == flag){
            ParserCmd::config->flag |= FLAG_TAB[i].flag_value;
            ParserCmd::flag_fill = i;
            return FLAG_TAB[i].arguments;
        }
    }
    ParserCmd::error = -1;
    return -1;
}

/*renvoie -1 en cas d'erreur*/
int Parsing::ParserCmd::is_flag(int pos, char **argument)
{
    int flag_type = 0;
    int skip_arg = 0;

    if (argument[pos][0] == '\0' || argument[pos][1] == '\0'){
        ParserCmd::error = -1;
        return -1;
    }
    flag_type += (argument[pos][0] == '-') ? 1 : 0;
    flag_type += (argument[pos][1] == '-') ? 1 : 0;
    if (flag_type == 0){
        ParserCmd::error = -1;
        return -1;
    }
    skip_arg = (flag_type == 1) ? 
        ParserCmd::find_short_flag(argument[pos][1]):
        ParserCmd::find_long_flag(argument[pos]);
    if (skip_arg == -1)
        return -1;
    return skip_arg;
}

Parsing::ParserCmd::ParserCmd(int ac, char **av)
    : config(std::make_unique<Parsing::Config>())
{
    ParserCmd::error = 0;
    int skip_arg = 0;

    if (ac == 2)
        return;

    for (int i = 2; i < ac; i++) {
        skip_arg = ParserCmd::is_flag(i, av);
        if (skip_arg == -1 || skip_arg + i >= ac){
            std::cerr << "Error to many arg\n";
            ParserCmd::error = -1;
            return;
        }
        if (FLAG_TAB->fill_flag(av, i, ParserCmd::config.get()) == false) {
            ParserCmd::error = -1;
            return;
        }
        i += skip_arg;
    }
    if (flag_conflict() == false){
        ParserCmd::error = -1;
        return;
    }
}