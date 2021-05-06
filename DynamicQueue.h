#pragma once

#include "SingleLinkList.h"

/// A Container giving @c FIFO behavior.
template<typename T>
class Queue
{
    LinkList<T> que;

public:

    bool enqueue(const T& data) { return que.insertAtEnd(data); }

    T dequeue() { return que.deleteFromHead(); }

    T& front() const { return que.get()->data; }

    T& back() const 
    { 
        auto temp = que.get();
        while(temp->next)
            temp = temp->next;
        return temp->data;
    }

    bool isEmpty() const { return (que.isEmpty()); }

    std::size_t size() const { return que.size(); }

    void clear() { que.clear(); }

};