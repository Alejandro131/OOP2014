#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
};

template <typename T>
class Stack
{
    public:

        Stack();
        Stack(const Stack<T>& other);
        Stack<T>& operator = (const Stack<T>& other);
        ~Stack();

        bool empty();
        bool peek(T& data);
        void push(const T& data);
        bool pop(T& data);

    private:

        void copyStack(const Stack<T>& other);
        void deleteStack();

        Node<T>* start;
};

template <typename T>
Stack<T>::Stack()
{
    start = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    start = 0;
    copyStack(other);
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& other)
{
    if (this != &other)
    {
        deleteStack();
        copyStack(other);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    deleteStack();
}

template <typename T>
bool Stack<T>::empty()
{
    return start == 0;
}

template <typename T>
bool Stack<T>::peek(T& data)
{
    if (!empty())
    {
        data = start->data;
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::push(const T& data)
{
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = start;
    start = node;
}

template <typename T>
bool Stack<T>::pop(T& data)
{
    if (!empty())
    {
        data = start->data;
        Node<T>* temp = start;
        start = start->next;
        delete temp;
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& other)
{
    Node<T>* current = other.start;
    Stack<T> reversed;
    while (current)
    {
        reversed.push(current->data);
        current = current->next;
    }
    T data;
    while (!reversed.empty())
    {
        reversed.pop(data);
        push(data);
    }
}

template <typename T>
void Stack<T>::deleteStack()
{
    T data;
    while (!empty())
    {
        pop(data);
    }
}

#endif
