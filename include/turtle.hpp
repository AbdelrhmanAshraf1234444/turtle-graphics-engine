#pragma once 

#include "canvas.hpp"
#include "color.hpp"

constexpr double PI = 3.1415;

namespace turtle
{

class Turtle
{
private:
    int x;
    int y;

    int angle; 
    bool penDownState; 

    Color penColor; 
    Canvas& canvas;
    void drawLine(int x1, int y1, int x2, int y2);

public:
    Turtle(Canvas& c);
    void penDown(int startX, int startY);
    void penUp();
    void moveForward(double  distance);
    void moveBackward(double distance);

    /* rotation */
    void turnRight(double  degrees);
    void turnLeft(double  degrees);

    /* color */
    void setPenColor(const Color& color);
};

}   // namespace turtle