#include <iostream>

#include "ColorLine.hpp"

ColorLine::ColorLine(unsigned _size):
    size(_size)
{
    pixels = new Pixel[size];
}

ColorLine::ColorLine(const ColorLine& other)
{
    copy(other);
}

ColorLine::~ColorLine()
{
    del();
}

ColorLine& ColorLine::operator=(const ColorLine& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

unsigned ColorLine::getSize() const
{
    return size;
}

const Pixel& ColorLine::operator[](unsigned index) const
{
    return pixels[index];
}

void ColorLine::sort()
{
    for (unsigned i = 0; i < size - 1; ++i)
    {
        unsigned min = i;

        for (unsigned j = i + 1; j < size; ++j)
        {
            if (pixels[min].getValue() > pixels[j].getValue())
            {
                min = j;
            }
        }

        if (min != i)
        {
            std::swap(pixels[min], pixels[i]);
        }
    }
}

void ColorLine::print() const
{
    std::cout << "[";

    for (unsigned i = 0; i < size - 1; ++i)
    {
        pixels[i].print();
        std::cout << ", ";
    }

    pixels[size - 1].print();

    std::cout << "]";
}

void ColorLine::setPixel(unsigned index, const Pixel& pixel)
{
    pixels[index] = pixel;
}

void ColorLine::copy(const ColorLine& other)
{
    size = other.size;
    pixels = new Pixel[size];

    for (unsigned i = 0; i < size; ++i)
    {
        pixels[i] = other.pixels[i];
    }
}

void ColorLine::del()
{
    delete[] pixels;
}
