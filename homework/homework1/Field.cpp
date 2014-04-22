#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>

#include "Field.hpp"

using namespace std;

struct Field::Cell
{
    int value;
    CELL_STATUS status;

    Cell(int _value=0):
        value(_value), status(CLOSED)
    { }
};

bool Field::seeded = false;

Field::Field(unsigned _width, unsigned _height, unsigned _mines):
    width(_width), height(_height), mines(_mines)
{
    if (!seeded)
    {
        srand(unsigned(time(0)));
        seeded = true;
    }

    cells = new Cell*[width];

    for (unsigned i = 0; i < width; ++i)
    {
        cells[i] = new Cell[height];
    }

    placeMines();
}

Field::Field(const Field& other)
{
    copy(other);
}

Field::~Field()
{
    del();
}

Field& Field::operator=(const Field& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

CELL_STATUS Field::cellStatus(unsigned x, unsigned y) const
{
    assert(areValidIndices(x, y));

    return cells[x][y].status;
}

int Field::cellValue(unsigned x, unsigned y) const
{
    assert(areValidIndices(x, y));

    return cells[x][y].value;
}

void Field::openCell(unsigned x, unsigned y)
{
    assert(areValidIndices(x, y));

    if (cells[x][y].status == CLOSED)
    {
        cells[x][y].status = OPEN;

        if (cells[x][y].value == 0)
        {
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    if ((i != 0 || j != 0) &&
                        areValidIndices(x + i, y + j))
                    {
                        openCell(x + i, y + j);
                    }
                }
            }
        }
    }
}

void Field::flagCell(unsigned x, unsigned y)
{
    assert(areValidIndices(x, y));

    if (cells[x][y].status == CLOSED)
    {
        cells[x][y].status = FLAGGED;
    }
}

void Field::unflagCell(unsigned x, unsigned y)
{
    assert(areValidIndices(x, y));

    if (cells[x][y].status == FLAGGED)
    {
        cells[x][y].status = CLOSED;
    }
}

bool Field::isSolved() const
{
    for (unsigned i = 0; i < width; ++i)
    {
        for (unsigned j = 0; j < height; ++j)
        {
            if (cells[i][j].status == CLOSED && cells[i][j].value != -1)
            {
                return false;
            }
        }
    }

    return true;
}

bool Field::hasExploded() const
{
    for (unsigned i = 0; i < width; ++i)
    {
        for (unsigned j = 0; j < height; ++j)
        {
            if (cells[i][j].value == -1 && cells[i][j].status == OPEN)
            {
                return true;
            }
        }
    }

    return false;
}

void Field::draw() const
{
    for (unsigned i = 0; i < width; ++i)
    {
        for (unsigned j = 0; j < height; ++j)
        {
            if (cells[i][j].status == CLOSED)
            {
                cout << "#";
            }
            else if (cells[i][j].status == FLAGGED)
            {
                cout << "!";
            }
            else if (cells[i][j].value == -1)
            {
                cout << "*";
            }
            else
            {
                cout << cells[i][j].value;
            }

            cout << " ";
        }

        cout << endl;
    }
}

bool Field::areValidIndices(unsigned x, unsigned y) const
{
    return x < width && y < height;
}

void Field::placeMines()
{
    unsigned randomX, randomY, minesCounter = 0;

    while (minesCounter < mines)
    {
        randomX = static_cast<unsigned>(rand() % width);
        randomY = static_cast<unsigned>(rand() % height);

        if (cells[randomX][randomY].value != -1)
        {
            cells[randomX][randomY].value = -1;
            updateNeighbours(randomX, randomY);
            ++minesCounter;
        }
    }
}

void Field::updateNeighbours(unsigned x, unsigned y)
{
    assert(areValidIndices(x, y));

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if ((i != 0 || j != 0) &&
                areValidIndices(x + i, y + j) &&
                cells[x + i][y + j].value != -1)
            {
                ++cells[x + i][y + j].value;
            }
        }
    }
}

void Field::copy(const Field& other)
{
    width  = other.width;
    height = other.height;
    mines  = other.mines;

    cells = new Cell*[width];

    for (unsigned i = 0; i < width; ++i)
    {
        cells[i] = new Cell[height];

        for (unsigned j = 0; j < height; ++j)
        {
            cells[i][j] = other.cells[i][j];
        }
    }
}

void Field::del()
{
    for (unsigned i = 0; i < width; ++i)
    {
        delete[] cells[i];
    }

    delete[] cells;
}
