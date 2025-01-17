#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
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

    while (!q.empty()) 
    {
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

int max_depth(Node* root) 
{
    if (root == NULL)
        return 0;
    int left_depth = max_depth(root->left);
    int right_depth = max_depth(root->right);
    return max(left_depth, right_depth) + 1;
}

int count_nodes(Node* root) 
{
    if (root == NULL)
        return 0;
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l + r + 1;
}

int main() 
{
    Node* root = input_tree();

    int depth = max_depth(root);
    int formula_total_nodes = pow(2, depth) - 1;
    int manual_total_nodes = count_nodes(root);

    if (formula_total_nodes == manual_total_nodes) 
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

