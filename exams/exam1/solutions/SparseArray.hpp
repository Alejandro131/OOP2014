#ifndef SPARSE_ARRAY_HPP
#define SPARSE_ARRAY_HPP

class SparseArray
{
public:
    SparseArray();
    SparseArray(const SparseArray&);
    ~SparseArray();

    SparseArray& operator=(const SparseArray&);

    int getValue(unsigned) const;
    bool containsIndex(unsigned) const;

    bool addItem(unsigned, int);
    bool removeItem(unsigned);

    unsigned getSize() const;
    bool isEmpty() const;

private:
    struct Item;

    Item* items;
    unsigned size;
    unsigned capacity;

    void expand();

    void copy(const SparseArray&);
    void del();
};

#endif
