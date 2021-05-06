#pragma once

#include<functional>

/// A Dynamic size Container.
template<typename T>
class DoublyLinkList
{
    struct Node { Node* prev; T data; Node* next; } *head;

    Node* reverse(Node* node)
    {
        if (!node) return NULL;

        Node* temp = node->next;
        node->next = node->prev;
        node->prev = temp;

        if (!node->prev) return node;

        return reverse(node->prev);
    }

public:

    DoublyLinkList() : head(NULL) {}

    ~DoublyLinkList() { clear(); }

    Node* get() const { return head; }

    void operator=(const DoublyLinkList<T>& obj)
    {
        clear();
        this->head = obj.head;
    }

    void clear() { delete head; head = NULL; }

    bool isEmpty() const { return (head == NULL); }

    bool insertAtHead(const T& data)
    {
        try 
        { 
            if (!head)
                head = new Node({ NULL, data, NULL }); 
            else
                head = head->prev = new Node({ NULL, data, head });
        }
        catch (...) { return false; }
        return true;
    }

    bool insertAtEnd(const T& data)
    {
        if (isEmpty())
            return insertAtHead(data);
        try
        {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = new Node({ temp, data, NULL });
        }
        catch (...) { return false; }
        return true;
    }

    T deleteFromHead()
    {
        if (isEmpty()) return T();
        T data = head->data;
        head = head->next;
        head->prev = NULL;
        return data;
    }

    T deleteFromEnd()
    {
        if (isEmpty()) return T();
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        T data = temp->next->data;
        temp->next = temp->next->prev = NULL;
        return data;
    }

    std::size_t size() const
    {
        std::size_t s = 0;
        Node* temp = head;
        while (temp) { s++; temp = temp->next; }
        return s;
    }

    void forEach(const std::function<void(T&)>& func)
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

    void reverse() { head = reverse(head); }

};