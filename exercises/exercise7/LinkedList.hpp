#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "LinkedListExceptions.hpp"

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();

    LinkedList& operator=(const LinkedList&);

    const T& getAt(unsigned) const;

    void insertAtBeginning(const T&);
    void insertAtEnd(const T&);
    void insertBefore(unsigned, const T&);
    void insertAfter(unsigned, const T&);

    void removeAt(unsigned);
    void removeBefore(unsigned);
    void removeAfter(unsigned);

    unsigned getSize() const;
    bool isEmpty() const;

private:
    struct Node;

    Node* start;
    unsigned size;

    Node* lookUp(unsigned);

    void copy(const LinkedList&);
    void del();
};

template <typename T>
LinkedList<T>::LinkedList():
    start(0), size(0)
{ }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    copy(other);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    del();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

template <typename T>
const T& LinkedList<T>::getAt(unsigned index) const
{
    Node* wantedItem = lookUp(index);

    if (wantedItem == 0)
    {
        throw IndexError();
    }
    else
    {
        return wantedItem->data;
    }
}

template <typename T>
void LinkedList<T>::insertAtBeginning(const T& item)
{
    Node* newNode = new Node(item, start);
    start = newNode;
    ++size;
}

template <typename T>
void LinkedList<T>::insertAtEnd(const T& item)
{
    insertAfter(size - 1, item);
}

template <typename T>
void LinkedList<T>::insertBefore(unsigned index, const T& item)
{
    if (index >= size)
    {
        throw IndexError();
    }

    if (index == 0)
    {
        insertAtBeginning(item);
    }
    else
    {
        Node* previous = lookUp(index - 1);
        Node* newNode  = new Node(item, previous->next);
        previous->next = newNode;

        ++size;
    }
}

template <typename T>
void LinkedList<T>::insertAfter(unsigned index, const T& item)
{
    if (index >= size)
    {
        throw IndexError();
    }

    Node* previous = lookUp(index);
    Node* newNode  = new Node(item, previous->next);
    previous->next = newNode;

    ++size;
}

template <typename T>
void LinkedList<T>::removeAt(unsigned index)
{
    if (index >= size)
    {
        throw IndexError();
    }

    Node* forRemoval;

    if (index == 0)
    {
        forRemoval = start;
        start = start->next;
    }
    else
    {
        Node* previous = lookUp(index - 1);

        forRemoval = previous->next;
        previous->next = forRemoval->next;
    }

    delete forRemoval;

    --size;
}

template <typename T>
void LinkedList<T>::removeBefore(unsigned index)
{
    if (index == 0)
    {
        throw IndexError();
    }

    removeAt(index - 1);
}

template <typename T>
void LinkedList<T>::removeAfter(unsigned index)
{
    removeAt(index + 1);
}

template <typename T>
unsigned LinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::lookUp(unsigned index)
{
    Node* iter = start;

    while (iter != 0 && index > 0)
    {
        iter = iter->next;
        --index;
    }

    return iter;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other)
{
    size = other.size;

    if (other.start == 0)
    {
        start = 0;
        return;
    }

    start = new Node(other.start->data);

    Node* iterThis  = start;
    Node* iterOther = other.start->next;

    while (iterOther != 0)
    {
        Node* newNode  = new Node(iterOther->data);
        iterThis->next = newNode;

        iterThis  = newNode;
        iterOther = iterOther->next;
    }
}

template <typename T>
void LinkedList<T>::del()
{
    Node* previous;

    while (start != 0)
    {
        previous = start;
        start    = start->next;

        delete previous;
    }
}

template <typename T>
struct LinkedList<T>::Node
{
    T data;
    Node* next;

    Node(const T&, Node* = 0);
};

template <typename T>
LinkedList<T>::Node::Node(const T& _data, Node* _next):
    data(_data), next(_next)
{ }

#endif
