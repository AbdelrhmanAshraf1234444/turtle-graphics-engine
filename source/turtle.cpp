#include "../include/turtle.hpp"
#include <cmath>
#include <algorithm>


namespace turtle
{
/*-------------------------------------------------------------*/
/*                      Constructor                            */
/*-------------------------------------------------------------*/
Turtle::Turtle(Canvas& c):x(0),y(0),angle(0)
                        ,penDownState(false),penColor(255,255,255),canvas(c)
{

}

/*-------------------------------------------------------------*/
/*                        Pen Control                          */
/*-------------------------------------------------------------*/
void Turtle::penDown(int startX, int startY)
{
    x = startX ;
    y = startY ;

    penDownState = true;
}

void Turtle::penUp()
{
    penDownState = false;
  
}


/*-------------------------------------------------------------*/
/*                        Rotation                             */
/*-------------------------------------------------------------*/
void Turtle::turnRight(double  degrees)
{
    angle += degrees;
}

void Turtle::turnLeft(double  degrees)
{
    angle -= degrees;
}

/*-------------------------------------------------------------*/
/*                        Movement                             */
/*-------------------------------------------------------------*/
void Turtle::moveForward(double  distance)
{
    /* convert degrees → radians */
    double rad = angle  * PI /180.0 ;

    /* calculate new position */
    double newX = x + distance * std::cos(rad);  
    double newY = y + distance * std::sin(rad);

    /* draw line if pen is down */
    if(penDownState)
    {
        drawLine((int)x, (int)y, (int)newX, (int)newY);

    }

    /* update turtle position */
    x = newX;
    y = newY;
}

void Turtle::moveBackward(double distance)
{
    /* convert degrees → radians */
    double rad = angle * PI / 180.0;

    /* calculate new position */
    double newX = x - distance * std::cos(rad);
    double newY = y - distance * std::sin(rad);

    /* draw line if pen is down */
    if(penDownState)
    {
        drawLine((int)x, (int)y, (int)newX, (int)newY);
    }

    /* update turtle position */
    x = newX;
    y = newY;
}

/*-------------------------------------------------------------*/
/*                     Set Pen Color                           */
/*-------------------------------------------------------------*/
void Turtle::setPenColor(const Color& color)
{
    penColor = color;

}

/*-------------------------------------------------------------*/
/*                      Line Drawing                           */
/*-------------------------------------------------------------*/
void Turtle::drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1 ;
    int dy = y2 - y1 ;

    int steps = std::abs(dx);
    if(std::abs(dy) > steps)
    {
        steps = std::abs(dy);
    }

    if(steps == 0)
    {
        return ;
    }

   float xStep = dx / (float)steps;
   float yStep = dy / (float)steps;

   float x = x1 ;
   float y = y1 ;

   for(int i = 0; i <= steps; i++)
   {
        canvas.setPixel((int)x, (int)y, penColor);

        x += xStep;
        y += yStep;
   }
}

}