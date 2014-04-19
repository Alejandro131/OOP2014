#include "SparseArray.hpp"

struct SparseArray::Item
{
    unsigned index;
    int value;

    Item();
    Item(unsigned, int);
};

SparseArray::Item::Item()
{ }

SparseArray::Item::Item(unsigned _index, int _value):
    index(_index), value(_value)
{ }

SparseArray::SparseArray():
    size(0), capacity(1)
{
    items = new Item[1];
}

SparseArray::SparseArray(const SparseArray& other)
{
    copy(other);
}

SparseArray::~SparseArray()
{
    del();
}

SparseArray& SparseArray::operator=(const SparseArray& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

int SparseArray::getValue(unsigned index) const
{
    return items[index].value;
}

bool SparseArray::containsIndex(unsigned index) const
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (items[i].index == index)
        {
            return true;
        }
    }

    return false;
}

bool SparseArray::addItem(unsigned index, int value)
{
    if (!containsIndex(index))
    {
        if (size == capacity)
        {
            expand();
        }

        items[size++] = Item(index, value);

        return true;
    }

    return false;
}

bool SparseArray::removeItem(unsigned index)
{
    unsigned itemIndex = 0;

    while (itemIndex < size && items[itemIndex].index != index)
    {
        ++itemIndex;
    }

    if (itemIndex == size)
    {
        return false;
    }

    for (unsigned i = itemIndex + 1; i < size; ++i)
    {
        items[i - 1] = items[i];
    }

    --size;

    return true;
}

unsigned SparseArray::getSize() const
{
    return size;
}

bool SparseArray::isEmpty() const
{
    return size == 0;
}

void SparseArray::expand()
{
    Item* oldItems = items;
    items = new Item[2 * capacity];

    for (unsigned i = 0; i < size; ++i)
    {
        items[i] = oldItems[i];
    }

    delete[] oldItems;

    capacity *= 2;
}

void SparseArray::copy(const SparseArray& other)
{
    size = other.size;
    capacity = other.capacity;

    items = new Item[size];

    for (unsigned i = 0; i < size; ++i)
    {
        items[i] = other.items[i];
    }
}

void SparseArray::del()
{
    delete[] items;
}
