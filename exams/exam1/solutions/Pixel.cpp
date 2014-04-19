#include <iostream>

#include "Pixel.hpp"

Pixel::Pixel():
    red(0), green(0), blue(0)
{ }

Pixel::Pixel(unsigned _red, unsigned _green, unsigned _blue):
    red(_red % 256), green(_green % 256), blue(_blue % 256)
{ }

unsigned Pixel::getRed() const
{
    return red;
}

unsigned Pixel::getGreen() const
{
    return green;
}

unsigned Pixel::getBlue() const
{
    return blue;
}

unsigned Pixel::getValue() const
{
    return 255 * 255 * red + 255 * green + blue;
}

void Pixel::setRed(unsigned _red)
{
    red = _red % 256;
}

void Pixel::setGreen(unsigned _green)
{
    green = _green % 256;
}

void Pixel::setBlue(unsigned _blue)
{
    blue = _blue % 256;
}

void Pixel::print() const
{
    std::cout << "[" << red << ", " << green << ", " << blue << "]";
}

bool Pixel::operator==(const Pixel& other) const
{
    return getValue() == other.getValue();
}

bool Pixel::operator!=(const Pixel& other) const
{
    return !(*this == other);
}

bool Pixel::operator<(const Pixel& other) const
{
    return getValue() < other.getValue();
}

bool Pixel::operator<=(const Pixel& other) const
{
    return !(other < *this);
}

bool Pixel::operator>(const Pixel& other) const
{
    return other < *this;
}

bool Pixel::operator>=(const Pixel& other) const
{
    return !(*this < other);
}

