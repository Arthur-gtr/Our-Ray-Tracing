#ifndef ENGINE_HPP
    #define ENGINE_HPP
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <cmath>

/*CLASS ENGINE*/


class Engine
    {
    private:  
        
    public:
        bool changed_view;
        /*Function to draw all the points in the z_buffer*/
        void draw_all();

        /*Builder*/
        Engine();
    };

#endif /*ENGINE_HPP*/
