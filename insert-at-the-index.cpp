#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node* prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(Node* head)
{
    Node* tmp = head;
    cout << "L -> ";
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node* tail)
{
    Node* tmp = tail;
    cout << "R -> ";
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int get_size(Node* head)
{
    int size = 0;
    Node* tmp = head;
    while(tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return size;
}

void insert_at_the_index(Node*& head, Node*& tail, int index, int value)
{
    Node* new_node = new Node(value);
    int size = get_size(head);

    if(index < 0 || index > size)
    {
        cout << "Invalid" << endl;
        return;
    }

    if(index == 0)
    {
        if(head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        print_forward(head);
        print_backward(tail);
        return;
    }

    if(index == size)
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        print_forward(head);
        print_backward(tail);
        return;
    }

    Node* tmp = head;
    for(int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }

    new_node->next = tmp->next;
    new_node->prev = tmp;
    tmp->next->prev = new_node;
    tmp->next = new_node;

    print_forward(head);
    print_backward(tail);
}

int main()
{
    int q;
    cin >> q;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < q; i++)
    {
        int x, v;
        cin >> x >> v;
        insert_at_the_index(head, tail, x, v);
    }

    return 0;
}
