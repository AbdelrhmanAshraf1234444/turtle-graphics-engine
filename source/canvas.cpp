#include "../include/canvas.hpp"
#include <fstream>
#include <iostream>



namespace turtle
{
Canvas::Canvas(int w, int h)
    : width(w), height(h), pixels(w * h, Color::Black())
{

}


void Canvas::setPixel(int x, int y, const Color& color)
{
    if(x < 0 || x >= width || y < 0 || y >= height)
    {
        return;
    }

    pixels[y * width + x] = color;
}

void Canvas::setBackground(const Color& color)
{
    for(auto& p : pixels)
    {
        p = color;
    }
}

Color Canvas::getPixel(int x, int y) const
{
    if(x < 0 || x >= width || y < 0 || y >= height)
    {
        return Color::Black();
    }

    return pixels[y * width + x];
}

void Canvas::savePPM(const std::string& filename) const
{
    std::ofstream outfile(filename);

    if(!outfile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    outfile << "P3\n";
    outfile << width << " " << height << "\n";
    outfile << "255\n";

    for(int y = 0; y < height; ++y)
    {
        for(int x = 0; x < width; ++x)
        {
            const Color& c = pixels[y * width + x];

            outfile << c.red << " "
                    << c.green << " "
                    << c.blue  << " ";
        }

        outfile << "\n";
    }
}

void Canvas::resize(int w, int h)
{
    width = w;
    height = h;

    pixels.assign(width * height, Color::Black());
}

int Canvas::getWidth() const
{
    return width;
}

int Canvas::getHeight() const
{
    return height;
}

}
