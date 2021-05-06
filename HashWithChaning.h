#pragma once

#include "SingleLinkList.h"
#include <iostream>

/// A HashTable with Chaning.
template<typename T, int size>
class HashTable
{
    LinkList<T> *Table;
    std::function<int(T, int)> hash;

public:

    HashTable(const std::function<int(T, int)>& hashFunction) 
        : hash(hashFunction)
    {
        Table = new LinkList<T>[size];
        for (int i = 0; i < size; i++)
            Table[i].clear();
    }

    ~HashTable() { delete[] Table; Table = NULL; }

    void insert(T key)
    {
        Table[hash(key, size)].insertAtHead(key);
    }

    void deletee(const T& key)
    {
        Table[hash(key, size)].remove(key);
    }

    bool search(const T& key)
    {
        return (Table[hash(key, size)].search(key));
    }

    void printTable()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << i << " => [";
            Table[i].forEach([](auto val){ std::cout << val << ", "; });
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }
};