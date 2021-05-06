#pragma once

#include <cstddef>
#include <utility>

/// A Container giving @c FIFO behavior.
template<typename T, std::size_t Size>
class CircularQueue
{
    std::size_t Front;
    std::size_t Back;
    T* Array;

public:

    CircularQueue() : Front(0), Back(0), Array(new T[Size]) {}

    ~CircularQueue() { delete[] Array; Array = NULL; }

    auto enqueue(const T& data)
    {
        if (isFull()) return std::pair<bool, T>(false, data);
        Array[(Back = ((Back + 1) % Size))] = data;
        return std::pair<bool, T>(true, data);
    }

    T dequeue()
    {
        if (Front >= Back) return T();
        return Array[(Front = ((Front + 1) % Size))];
    }

    T peek(size_t index) const { return Array[Front + index]; }

    bool isEmpty() const { return (Back == Front); }

    bool isFull() const { return ((Back + 1) % Size) == Front; }

    std::size_t size() const { return Size; }

    T& front() const { return Array[Front + 1]; }

    T& back() const { return Array[Back]; }

};