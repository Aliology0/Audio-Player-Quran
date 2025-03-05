#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include "surah.h"

using namespace std;
class Node
{
public:
    Surah *surah;
    Node *next;
    Node *prev;

    Node(Surah *sur)
    {
        surah = sur;
        next = nullptr;
        prev = nullptr;
    }
};

class Playlist
{
private:
    string Name;
    Node *head;
    Node *tail;
    size_t size;

public:
    Playlist(string n) : Name(n), head(nullptr), tail(nullptr), size(0) {}

    void AddSurah(Surah *surah)
    {
        Node *newNode = new Node(surah);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void RemoveSurah(Surah *surah)
    {
        Node *current = head;
        while (current)
        {
            if (current->surah == surah)
            {
                if (current->prev)
                    current->prev->next = current->next;
                else
                    head = current->next;
                if (current->next)
                    current->next->prev = current->prev;
                else
                    tail = current->prev;
                delete current;
                size--;
                return;
            }
            current = current->next;
        }
    }

    void DisplayAllSurahs()
    {
        Node *current = head;
        while (current)
        {
            cout << "Surah: " << current->surah->getName() << ", Type: " << current->surah->getType() << ", Path: " << current->surah->getPath() << endl;
            current = current->next;
        }
    }

    string getName()
    {
        return Name;
    }
    Node *GetHead()
    {
        return head;
    }
    Node *GetTail()
    {
        return tail;
    }
    size_t GetSize()
    {
        return size;
    }

    Node *GetNextSurah(Node *current)
    {
        if (current && current->next)
            return current->next;
        return nullptr;
    }

    Node *GetPreviousSurah(Node *current)
    {
        if (current && current->prev)
            return current->prev;
        return nullptr;
    }

    ~Playlist()
    {
        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp->surah;
            delete temp;
        }
    }
};

#endif // PLAYLIST_H
