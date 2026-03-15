#pragma once 


namespace turtle
{

struct Color
{

    int red;
    int green;
    int blue;

    Color(int r = 0, int g = 0, int b = 0);

    /* predefined colors */
    static Color Red();
    static Color Green();
    static Color Blue();
    static Color White();
    static Color Black();
    static Color Yellow();

};

    
} // namespace turtle
