#include "../include/script_parser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace turtle
{
ScriptParser::ScriptParser(Turtle& t, Canvas& c) : turtle(t) , canvas(c)
{

}

Color ScriptParser::parseColorName(const std::string& name)
{
    std::string lowerName = name ;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    if(lowerName == "red")      return Color::Red();
    if(lowerName == "green")    return Color::Green();
    if(lowerName == "blue")     return Color::Blue();
    if(lowerName == "yellow")   return Color::Yellow();
    if(lowerName == "white")    return Color::White();
    if(lowerName == "black")    return Color::Black();

    std::cerr << "Unknown color: " << name << std::endl;
    return Color::White(); // default white
}

int ScriptParser::parseInt(const std::string& token)
{
    return std::stoi(token) ;
}

bool ScriptParser::parseLine(const std::string& line)
{
    std::string l = line;

    // ignore comments and empty line 
    if((l.empty()) || (l[0] == '#'))
    {
        return true ;
    }

    std::stringstream ss(l);
    std::string cmd1, cmd2;

    ss >> cmd1 ;

    // lowercase for comparison
    std::transform(cmd1.begin(), cmd1.end(), cmd1.begin(), ::tolower);
    std::transform(cmd2.begin(), cmd2.end(), cmd2.begin(), ::tolower);

    // "color pen=blue bg=yellow"
    if(cmd1 == "size")
    {
        std::string wtoken,htoken;
        ss >> wtoken >> htoken;

        int w = parseInt(wtoken.substr(wtoken.find('=')+1));
        int h = parseInt(htoken.substr(htoken.find('=')+1));

        canvas.resize(w,h);

        return true ;
    }

    //"color pen=blue bg=yellow"
    if(cmd1 == "color")
    {
        std::string penToken, bgToken;
        ss >> penToken >> bgToken ;

        // pen color
        std::string penColorName = penToken.substr(penToken.find('=')+1);
        Color penColor  = parseColorName(penColorName);
        turtle.setPenColor(penColor );

        std::string bgColorName = bgToken.substr(bgToken.find('=')+1);
        Color bgColor = parseColorName(bgColorName);
        canvas.setBackground(bgColor);

        return true;
    }



    // "pen down 0 0" or "pen up"
    if(cmd1 == "pen")
    {
        ss >> cmd2 ;

        if(cmd2 == "down")
        {
            int x, y;
            ss >> x >> y;
            turtle.penDown(x,y);
        } 
        else if(cmd2 == "up")
        {
            turtle.penUp();
        }
        else
        {
            std::cerr << "Unknown pen command: " << cmd2 << std::endl;
            return false;
        }

        return true;

    }

    // "move forward 100" or "move right 144"
    if(cmd1 == "move" || cmd1 == "turn" )
    {
        std::string direction;
        int value;  
        ss >> direction >> value ;
        std::transform(direction.begin(), direction.end(), direction.begin(), ::tolower);

        if(direction == "forward")
        {
            turtle.moveForward(value);
        }
        else if(direction == "backward")
        {
            turtle.moveBackward(value);

        }
        else if(direction == "right")
        {
            turtle.turnRight(value);
        }
        else if(direction == "left")
        {
            turtle.turnLeft(value);
        } 
        else
        {
            std::cerr << "Unknown move direction: " << direction << std::endl;
            return false;
        }


        return true;
    }

    std::cerr << "Unknown command: " << line << std::endl;
    return false;
}

bool ScriptParser::parseFile(const std::string& filename)
{
    std::ifstream file(filename);
    
    if(!file.is_open())
    {
        std::cerr << "Cannot open script file: " << filename << std::endl;
        return false;
    }

    std::string line;
    int lineNumber = 0;

    while(std::getline(file,line))
    {
        lineNumber++;
        if(!parseLine(line))
        {
            std::cerr << "Error in line " << lineNumber << ": " << line << std::endl;
            return false; // stop execution on error
        }
    }

    return true;
}
}