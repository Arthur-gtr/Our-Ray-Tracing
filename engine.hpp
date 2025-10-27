#ifndef ENGINE_HPP
    #define ENGINE_HPP
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <cmath>

/*CLASS ENGINE*/


class Engine
    {
    private:  
        uint32_t flag;
    public:
        bool parse_flag(int ac, char **av);
        Engine();
    };

#endif /*ENGINE_HPP*/
