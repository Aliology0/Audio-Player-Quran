#ifndef DOUBLELL_H
#define DOUBLELL_H

#include <iostream>
using namespace std;
template <typename T>

struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Insert node at the beginning
    void insertAtBeginning(T element)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = element;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
        size++;
    }

    // Insert node at the end
    void insertAtEnd(T element)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = element;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail)
        {
            tail->next = newNode;
        }
        else
        {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    // Remove node from the beginning
    void removeFirst()
    {
        if (!head)
        {
            cout << "List is empty." << "\n";
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    // Remove node from the end
    void removeLast()
    {
        if (!tail)
        {
            cout << "List is empty." << "\n";
            return;
        }
        Node<T> *temp = tail;
        tail = tail->prev;
        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
        size--;
    }

    // Display the list
    void display()
    {
        cout << "List: ";
        Node<T> *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Display the list in reverse order
    void reverseDisplay()
    {
        cout << "List in reverse order: ";
        Node<T> *temp = tail;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    ~DoublyLinkedList()
    {
        Node<T> *current = head;
        while (current)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
};

#endif // DOUBLELL_H
