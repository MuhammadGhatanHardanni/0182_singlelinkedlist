#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class List
{
    Node *START;

public:
    List()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikat noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next =START;
            START = nodeBaru;
            return;
        }
        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikat noMhs tidak diijinkan\n";
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool Search(int nim, Node **Previous, Node **Current)
    {
        *Previous = START;
        *Current = START;

        while ((*Current != NULL) && (nim != (*Current)->noMhs))
        {
            *Previous = *Current;
            *Current = (*Current)->next;
        }

        return (*Current != NULL);
    }
};