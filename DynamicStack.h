#pragma once

#include "SingleLinkList.h"

/// A Container giving @c LIFO behavior.
template<typename T>
class Stack
{
    LinkList<T> top;

public:

    bool push(const T& data) { return top.insertAtHead(data); }

    T pop() { return top.deleteFromHead(); }

    T& peek() const { return top.get()->data; }

    bool isEmpty() const { return (top.isEmpty()); }

    std::size_t size() const { return top.size(); }

    void clear() { top.clear(); }
};