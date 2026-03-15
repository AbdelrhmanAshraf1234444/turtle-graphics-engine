#pragma once

#include "turtle.hpp"
#include "canvas.hpp"
#include "color.hpp"


namespace turtle
{
class ScriptParser
{
private:
    Turtle& turtle;   // reference to the turtle
    Canvas& canvas;   // reference to the canvas

    Color parseColorName(const std::string& name);  // convert color name to Color
    int parseInt(const std::string& token);        // convert string to int safely

public:
    ScriptParser(Turtle& t, Canvas& c);

    bool parseFile(const std::string& filename);

    bool parseLine(const std::string& line);

};

}
