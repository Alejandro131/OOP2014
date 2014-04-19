#ifndef PIXEL_HPP
#define PIXEL_HPP

class Pixel
{
public:
    Pixel();
    Pixel(unsigned, unsigned, unsigned);

    unsigned getRed  () const;
    unsigned getGreen() const;
    unsigned getBlue () const;

    unsigned getValue() const;

    void setRed  (unsigned);
    void setGreen(unsigned);
    void setBlue (unsigned);

    void print() const;

    bool operator==(const Pixel&) const;
    bool operator!=(const Pixel&) const;
    bool operator< (const Pixel&) const;
    bool operator>=(const Pixel&) const;
    bool operator> (const Pixel&) const;
    bool operator<=(const Pixel&) const;

private:
    unsigned red;
    unsigned green;
    unsigned blue;
};

#endif
