#include "../include/color.hpp"

namespace turtle
{
/*-------------------------------------------------------------*/
/*                         Constructor                         */
/*-------------------------------------------------------------*/
Color::Color(int r, int g, int b)
    : red(r), green(g), blue(b)
{
}
Color Color::Red()
{
    return Color(255,0,0);
}

Color Color::Green()
{
    return Color(0,255,0);
}

Color Color::Blue()
{
    return Color(0,0,255);
}

Color Color::White()
{
    return Color(255,255,255);
}

Color Color::Black()
{
    return Color(0,0,0);
}

Color Color::Yellow()
{
    return Color(255,255,0);
}


}
