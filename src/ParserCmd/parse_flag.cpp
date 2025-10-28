#include <cstring>

#include "parser_cmd.hpp"

/*Tableau pour parser les flags de compilation en 
sachant que certain flag comme -C peut contenir des 
petit flag indispensable pour déterminer dans le cas présent
l'Ip et le port ces petit flag n'ont pas de grand nom a l'instar
de tous les autre de flag.*/
const Parsing::flag_t FLAG_TAB[] = {
    {.long_flag = "graphical",  .short_flag = 'G', .arguments = 0, .arguments_type = 0,                 .flag_in = nullptr},
    {.long_flag = "usage",      .short_flag = 'U', .arguments = 1, .arguments_type = Parsing::TYPE_STR, .flag_in = nullptr},
    {.long_flag = "thread",     .short_flag = 'T', .arguments = 1, .arguments_type = Parsing::TYPE_INT, .flag_in = nullptr},
    {.long_flag = "debug",      .short_flag = 'D', .arguments = 0, .arguments_type = 0,                 .flag_in = nullptr},
    {.long_flag = "verbose",    .short_flag = 'V', .arguments = 0, .arguments_type = 0,                 .flag_in = nullptr}, 
    {.long_flag = "real-time",  .short_flag = 'R', .arguments = 0, .arguments_type = 0,                 .flag_in = nullptr}, 
    {.long_flag = "stop-dream", .short_flag = 'S', .arguments = 0, .arguments_type = 0,                 .flag_in = nullptr},
    {.long_flag = "clustering", .short_flag = 'C', .arguments = 1, .arguments_type = Parsing::TYPE_STR, .flag_in = "ip"},
    {.long_flag = NULL,      .short_flag = 'i', .arguments = 1, .arguments_type = Parsing::TYPE_IP,     .flag_in = nullptr},
    {.long_flag = NULL,      .short_flag = 'p', .arguments = 1, .arguments_type = Parsing::TYPE_INT,    .flag_in = nullptr},
};

const size_t SIZE_TAB = sizeof(FLAG_TAB) / sizeof(*FLAG_TAB);

/*renvoie -1 en cas d'erreur*/
int Parsing::ParserCmd::find_long_flag(char *flag)
{
    flag += 2;

    for (int i = 0; i < SIZE_TAB; i++){
        if (FLAG_TAB[i].long_flag == NULL)
            continue;
        if (strcmp(FLAG_TAB[i].long_flag, flag) == 0)
            return FLAG_TAB[i].arguments;
    }
    ParserCmd::error = -1;
    return -1;
}

int Parsing::ParserCmd::find_short_flag(char flag)
{
    for (int i = 0; i < SIZE_TAB; i++){
        if (FLAG_TAB[i].short_flag == flag)
            return FLAG_TAB[i].arguments;
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
{
    int skip_arg = 0;

    for (int i = 1; i < ac; i++) {
        skip_arg = ParserCmd::is_flag(i, av);
        if (skip_arg == -1 || skip_arg + i >= ac)
            return;
        i += skip_arg;
    }
}