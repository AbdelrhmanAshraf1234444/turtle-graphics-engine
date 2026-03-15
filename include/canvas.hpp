#pragma once 
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include "color.hpp"

namespace turtle
{
class  Canvas
{
private:
    /* data */
    int width ;
    int height ;
    std::vector<Color> pixels ;

public:
    Canvas(int w, int h);

    void setPixel(int x, int y, const Color& color);
    void setBackground(const Color& color);

    Color getPixel(int x, int y) const;

    void savePPM(const std::string& filename) const;

    void resize(int w, int h);

    int getWidth() const;
    int getHeight() const;


};

}   // namespace turtle