#pragma once

#include <cstddef>
#include <utility>

/// A Container giving @c LIFO behavior.
template<typename T, std::size_t Size>
class Stack
{
    std::size_t top;
    T* Array;

public:

    Stack() : top(0), Array(new T[Size]) {}

    ~Stack() { delete[] Array; Array = NULL; }

    auto push(const T& data)
    {
        if (isFull()) return std::pair<bool, T>(false, data);
        Array[top++] = data;
        return std::pair<bool, T>(true, data);
    }

    T pop()
    {
        if (isEmpty()) return T();
        return Array[--top];
    }

    T peek() const 
    { 
        if (isEmpty()) return T();
        return Array[top - 1]; 
    }

    bool isEmpty() const { return (top == 0); }

    bool isFull() const { return (top >= Size); }

    std::size_t size() const { return Size; }

    void clear() { top = 0; }

};