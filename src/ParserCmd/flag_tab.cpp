#include "parser_cmd.hpp"

/*Tableau pour parser les flags de compilation en 
sachant que certain flag comme -C peut contenir des 
petit flag indispensable pour déterminer dans le cas présent
l'Ip et le port ces petit flag n'ont pas de grand nom a l'instar
de tous les autre de flag.*/
const Parsing::flag_t FLAG_TAB[] = {
    {.long_flag = "graphical",  .short_flag = 'G', .arguments = 0, .arguments_type = 0,                 .flag_need = {'\0'}, .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_G},
    {.long_flag = "usage",      .short_flag = 'U', .arguments = 1, .arguments_type = Parsing::TYPE_STR, .flag_need = {'\0'}, .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_U},
    {.long_flag = "thread",     .short_flag = 'T', .arguments = 1, .arguments_type = Parsing::TYPE_INT, .flag_need = {'\0'}, .flag_exclude = "U"   , .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_T},
    {.long_flag = "debug",      .short_flag = 'D', .arguments = 0, .arguments_type = 0,                 .flag_need = {'\0'}, .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_D},
    {.long_flag = "verbose",    .short_flag = 'V', .arguments = 0, .arguments_type = 0,                 .flag_need = {'\0'}, .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_V}, 
    {.long_flag = "real-time",  .short_flag = 'R', .arguments = 0, .arguments_type = 0,                 .flag_need = "U",    .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_R}, 
    {.long_flag = "stop-dream", .short_flag = 'S', .arguments = 0, .arguments_type = 0,                 .flag_need = {'\0'}, .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_S},
    {.long_flag = "clustering", .short_flag = 'C', .arguments = 1, .arguments_type = Parsing::TYPE_STR, .flag_need = "ip"  , .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_C},
    {.long_flag = {'\0'},       .short_flag = 'i', .arguments = 1, .arguments_type = Parsing::TYPE_IP,  .flag_need = {'\0'}, .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_I},
    {.long_flag = {'\0'},       .short_flag = 'p', .arguments = 1, .arguments_type = Parsing::TYPE_INT, .flag_need = {'\0'}, .flag_exclude = {'\0'}, .fill_flag=Parsing::fill_g, .flag_value=Parsing::FLAG_P},
};


const size_t SIZE_TAB = sizeof(FLAG_TAB) / sizeof(*FLAG_TAB);
