/*--------------------------------------------------------------------------*/
/*                      Turtle Graphics Engine - Main                       */
/*--------------------------------------------------------------------------*/

/*
    Author      : Abdelrahman Ashraf Gomaa
    Specialty   : Embedded Systems Engineer

    Project     : Turtle Graphics Engine
    Description :
    ------------------------------------------------------------------------
    This project implements a Turtle Graphics system written in Modern C++.
    The engine reads a custom script file containing drawing commands and
    renders the result as an image.

    The system simulates a virtual "turtle" that moves on a canvas and draws
    lines based on movement and rotation commands.

    Features:
        - Script based drawing system
        - Custom script parser
        - Canvas rendering engine
        - Turtle movement simulation
        - Support for multiple colors
        - Image generation in PPM format
        - Interactive script generator

    Example Commands:
        move forward <distance>
        move backward <distance>
        turn right <degrees>
        turn left <degrees>
        pen down <x> <y>
        pen up
        color pen=<color> bg=<color>

    Output:
        The program generates an image file representing the executed
        drawing commands.

    Language        : C++
    Standard        : Modern C++ (C++17)
    Compiler        : GCC / MinGW
    Platform        : Windows / Linux

    Project Start   : 2026
    Version         : 1.0

    ------------------------------------------------------------------------
    This project demonstrates the use of:
        - Object-Oriented Programming (OOP)
        - File Parsing
        - Custom Script Languages
        - Graphics Rendering
        - Modern C++ Design

*/
#include <iostream>
#include <fstream>

#include "../include/color.hpp"
#include "../include/canvas.hpp"
#include "../include/turtle.hpp"
#include "../include/script_parser.hpp"
#include "../include/script_generator.hpp"

int main()
{
    int choice;

    std::cout << "==== Turtle System ====\n";
    std::cout << "1) Create New Script\n";


    runScriptGenerator();  


    turtle::Canvas canvas(200,200);
    turtle::Turtle turtle(canvas);
    turtle::ScriptParser parser(turtle, canvas);

    parser.parseFile("test.turtle");
    canvas.savePPM("output.ppm");

    std::cout << "Image generated successfully\n";
    std::system("start output.ppm");
    return 0;
}