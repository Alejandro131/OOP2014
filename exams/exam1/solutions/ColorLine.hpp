#ifndef COLOR_LINE_HPP
#define COLOR_LINE_HPP

#include "Pixel.hpp"

class ColorLine
{
public:
    ColorLine(unsigned);
    ColorLine(const ColorLine&);
    ~ColorLine();

    ColorLine& operator=(const ColorLine&);

    unsigned getSize() const;
    const Pixel& operator[](unsigned) const;

    void sort();
    void print() const;
    void setPixel(unsigned, const Pixel&);

private:
    Pixel* pixels;
    unsigned size;

    void copy(const ColorLine&);
    void del();
};

#endif
