#pragma once

#include <cstddef>
#include <utility>

/// A Container giving @c FIFO behavior.
template<typename T, std::size_t Size>
class Queue
{
    std::size_t Front;
    std::size_t Back;
    T *Array;

public:

    Queue() : Front(0), Back(0), Array(new T[Size]) {}

   ~Queue() { delete[] Array; Array = NULL; }

    auto enqueue(const T& data)
    {
        if (isFull()) return std::pair<bool, T>(false, data);
        Array[Back++] = data;
        return std::pair<bool, T>(true, data);
    }

    T dequeue() 
    {
        if (Front >= Back) return T();
        return Array[Front++];
    }

    T peek(std::size_t index) const { return Array[Front + index]; }

    bool isEmpty() const { return (Back == Front); }

    bool isFull() const { return (Back >= Size); }

    std::size_t size() const { return Size; }

    T& front() const { return Array[Front]; }

    T& back() const { return Array[Back - 1]; }

    void reset(bool forcefully = false) { if (forcefully || isEmpty()) Front = Back = 0; }

};