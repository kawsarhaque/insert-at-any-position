#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) 
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() 
{
    int val;
    cin >> val;
    Node* root;
    if (val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* myLeft;
        if (l == -1) myLeft = NULL;
        else myLeft = new Node(l);

        Node* myRight;
        if (r == -1) myRight = NULL;
        else myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (myLeft) q.push(myLeft);
        if (myRight) q.push(myRight);
    }
    return root;
}

void print_level_nodes(Node* root, int level) 
{
    if (root == NULL) {
        cout << "Invalid" << endl;
        return;
    }

    if (level < 0) {
        cout << "Invalid" << endl;
        return;
    }

    queue<pair<Node*, int>> q;
    
    q.push({root, 0});

    bool found = false;
    
    while (!q.empty()) 
    {
        Node* curr = q.front().first;
        int curr_level = q.front().second;
        q.pop();

        if (curr_level == level) 
        {
            cout << curr->val << " ";
            found = true;
        }

        if (curr_level > level) break;

        if (curr->left) q.push({curr->left, curr_level + 1});
        if (curr->right) q.push({curr->right, curr_level + 1});
    }

    if (!found) {
        cout << "Invalid" << endl;
    }
}

int main() 
{
    Node* root = input_tree();

    int level;
    cin >> level;

    print_level_nodes(root, level);
    
    return 0;
}


