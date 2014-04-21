#include <iostream>

using namespace std;

template <typename T>
class Vector;

template <typename T>
ostream& operator<<(ostream& outputStream, const Vector<T>& vector)
{
    outputStream << "[";

    for (unsigned i = 0; i < vector.size() - 1; ++i)
    {
        outputStream << vector[i] << ", ";
    }

    outputStream << vector[vector.size() - 1] << "]";

    return outputStream;
}

template <typename T>
istream& operator>>(istream& inputStream, Vector<T>& vector)
{
    T item;

    while (inputStream >> item)
    {
        vector.pushBack(item);
    }

    return inputStream;
}
