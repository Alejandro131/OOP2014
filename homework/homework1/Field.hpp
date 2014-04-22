#ifndef FIELD_HPP
#define FIELD_HPP

enum CELL_STATUS {OPEN, CLOSED, FLAGGED};

class Field
{
public:
    Field(unsigned, unsigned, unsigned);
    Field(const Field&);
    ~Field();

    Field& operator=(const Field&);

    CELL_STATUS cellStatus(unsigned, unsigned) const;
    int cellValue(unsigned, unsigned) const;

    void openCell(unsigned, unsigned);
    void flagCell(unsigned, unsigned);
    void unflagCell(unsigned, unsigned);

    bool isSolved() const;
    bool hasExploded() const;

    void draw() const;

private:
    struct Cell;

    Cell** cells;

    unsigned width;
    unsigned height;
    unsigned mines;

    static bool seeded;

    bool areValidIndices(unsigned, unsigned) const;

    void placeMines();
    void updateNeighbours(unsigned, unsigned);

    void copy(const Field&);
    void del();
};

#endif
