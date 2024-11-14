#pragma once

#include <iostream>

/// A BST Container.
template<typename T>
class BST
{
    struct Node { Node* left; T data; Node* right; } *root;

    void inorder(Node* root) const
    {
        if (root != NULL)
        {
            if (root->left) inorder(root->left);
            std::cout << root->data << std::endl; 
            if (root->right) inorder(root->right);
        }
    }

    void preorder(Node* root) const
    {
        if (root != NULL)
        {
            std::cout << root->data << std::endl; 
            if (root->left) preorder(root->left);
            if (root->right) preorder(root->right);
        }
    }

    void postorder(Node* root) const
    {
        if (root != NULL)
        {
            if (root->left) postorder(root->left);
            if (root->right) postorder(root->right);
            std::cout << root->data << std::endl; 
        }
    }

    Node* insert(Node* temp, const T& data)
    {
        if (temp == NULL)
            temp = new Node({ NULL, data, NULL });
        else if (data < temp->data)
            temp->left = insert(temp->left, data);
        else if (data > temp->data)
            temp->right = insert(temp->right, data);
        return temp;
    }

    template<typename X>
    Node* remove(Node* root, const X& data)
    {
        if (root == NULL)
            return root;
        else if (data < root->data)
            root->left = remove(root->left, data);
        else if (data > root->data)
            root->right = remove(root->right, data);
        else
        {
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;
            else
            {
                Node* temp = findMinNode(root->right);
                root->data = temp->data;
                root->right = remove(root->right, temp->data);
            }
        }
        return root;
    }

    void print2D(Node* root, int space) {
        if (root != NULL)
        {
            space += 10;
            print2D(root->right, space);
            std::cout << std::endl;
            for (int i = 10; i < space; i++)
                std::cout << " ";
            std::cout << root->data << std::endl;
            print2D(root->left, space);
        }
    }

    Node* findMinNode(Node* root) { return (!root || !root->left) ? root : findMinNode(root->left); }

public:

    BST() : root(NULL) {}

    ~BST() { clear(); }

    void clear() { delete root; root = NULL; }

    bool isEmpty() const { return (root == NULL); }

    void display(int which = 2) const 
    { 
        return (which == 1) ? preorder(root) : (which == 2) ? inorder(root) : postorder(root);
    }

    void print2D(int space = 2) { print2D(root, space); }

    bool insert(const T& data)
    {
        if (search(data)) return false;
        try { root = insert(root, data); }
        catch (...) { return false; }
        return true;
    }

    template<typename X>
    Node* search(const X& data)
    {
        if (isEmpty()) return NULL;

        Node* temp = root;

        while (temp != NULL)
        {
            if (temp->data == data) return temp;
            else temp = (data > temp->data) ? temp->right : temp->left;
        }
        return NULL;
    }

    template<typename X>
    bool remove(const X& data)
    {
        if (!search(data)) return false;
        root = remove(root, data);
        return true;
    }
};
