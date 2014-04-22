#include <ctime>
#include <stdlib.h>

#include "MoneyStream.hpp"

bool MoneyStream::seeded = false;

MoneyStream::MoneyStream(unsigned int _size):
    size(_size)
{
    if (!seeded)
    {
        srand(unsigned(time(0)));
        seeded = true;
    }

    stream = new double[size];

    for (unsigned int i = 0; i < size; ++i)
    {
        stream[i] = rand() % 100;
    }
}

MoneyStream::MoneyStream(const MoneyStream& other)
{
    copy(other);
}

MoneyStream::~MoneyStream()
{
    del();
}

unsigned int MoneyStream::getSize() const
{
    return size;
}

double MoneyStream::getValue(unsigned int index)
{
    double value = stream[index];
    stream[index] = -1;

    return value;
}

bool MoneyStream::isAvailable(unsigned int index) const
{
    return stream[index] == -1;
}

bool MoneyStream::hasAvailable() const
{
    for (unsigned int i = 0; i < size; ++i)
    {
        if (stream[i] != -1)
        {
            return true;
        }
    }

    return false;
}

MoneyStream& MoneyStream::operator=(const MoneyStream& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

void MoneyStream::copy(const MoneyStream& other)
{
    size = other.size;

    stream = new double[size];

    for (unsigned int i = 0; i < size; ++i)
    {
        stream[i] = other.stream[i];
    }
}

void MoneyStream::del()
{
    delete[] stream;
}
