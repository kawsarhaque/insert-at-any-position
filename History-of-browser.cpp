#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string address;
    Node *next;
    Node *prev;

    Node(string address)
    {
        this->address = address;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insert_at_tail(Node *&head, Node *&tail, string address)
{
    Node *new_node = new Node(address);
    if (head == NULL)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}


void visit(Node *&current, Node *head, string address)
{
    Node *tmp = head;
    
    while (tmp != NULL)
    {
        if (tmp->address == address)
        {
            current = tmp;
            cout << address << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "Not Available" << endl;
}


void move_next(Node *&current)
{
    if (current == NULL || current->next == NULL)
    {
        cout << "Not Available" << endl;
    }
    else
    {
        current = current->next;
        cout << current->address << endl;
    }
}


void move_prev(Node *&current)
{
    if (current == NULL || current->prev == NULL)
    {
        cout << "Not Available" << endl;
    }
    else
    {
        current = current->prev;
        cout << current->address << endl;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    
    string address;
    
    while (cin >> address && address != "end")
    {
        insert_at_tail(head, tail, address);
    }

    int q; 
    
    cin >> q;

    Node *current = NULL;

   
    for (int i = 0; i < q; i++)
    {
        string check;
        cin >> check;

        if (check == "visit")
        {
            string another_address;
            cin >> another_address;
            visit(current, head, another_address);
        }
        else if (check == "next")
        {
            move_next(current);
        }
        else if (check == "prev")
        {
            move_prev(current);
        }
    }

    return 0;
}
