#pragma once

#include<functional>

/// A Dynamic size Container.
template<typename T>
class LinkList
{
    struct Node { T data; Node *next; } *head;

public:

    LinkList() : head(NULL) {}

    ~LinkList() { clear(); }

    Node* get() const { return head; }

    void operator=(const LinkList<T> &obj)
    {
        clear();
        this->head = obj.head;
    }

    void clear() { delete head; head = NULL; }

    bool isEmpty() const { return (head == NULL); }

    bool insertAtHead(const T& data)
    {
        try { head = new Node({ data, head }); }
        catch (...) { return false; }
        return true;
    }

    bool insertAtEnd(const T& data)
    {
        if (isEmpty()) 
            return insertAtHead(data);
        try 
        {
            Node *temp = head;
            while(temp->next)
                temp = temp->next;
            temp->next = new Node({ data, NULL });
        }
        catch (...) { return false; }
        return true;
    }

    T deleteFromHead() 
    { 
        if (isEmpty()) return T();
        T data = head->data;
        head = head->next;
        return data;
    }

    T deleteFromEnd() 
    { 
        if (isEmpty()) return T();
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        T data = temp->next->data;
        temp->next = NULL;
        return data;
    }

    void remove(const T& key)
    {
        if (head->data == key)
            head = head->next;
        else
        {
            Node *temp = this->head, *newtemp = NULL;
            while (temp->next != NULL && temp->next->data != key)
                temp = temp->next;
            newtemp = temp;
            temp = temp->next;
            newtemp->next = temp->next;
        }
    }

    std::size_t size() const 
    {
        std::size_t s = 0;
        Node* temp = head;
        while (temp) { s++; temp = temp->next; }
        return s;
    }

    void forEach(const std::function<void(T&)> &func)
    {
        Node* temp = head;
        while (temp)
        {
            func(temp->data);
            temp = temp->next;
        }
    }

    Node* search(const T& value)
    {
        if (isEmpty() || head->data == value) return head;
        Node* temp = head;
        while (temp) 
        {
            if (temp->data == value)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void reverse()
    {
        Node* current = head;
        Node* prev = NULL, * next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};