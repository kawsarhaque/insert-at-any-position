#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}


void printLeftBoundaryBottomToTop(Node *root, vector<int> &leftBoundary)
{
    if (root == NULL)
        return;


    if (root->left)
    {
        printLeftBoundaryBottomToTop(root->left, leftBoundary);
    }
    else if (root->right)
    {
        printLeftBoundaryBottomToTop(root->right, leftBoundary);
    }


    leftBoundary.push_back(root->val);
}


void printRightBoundaryTopToBottom(Node *root, vector<int> &rightBoundary)
{
    if (root == NULL)
        return;


    rightBoundary.push_back(root->val);


    if (root->right)
    {
        printRightBoundaryTopToBottom(root->right, rightBoundary);
    }
    else if (root->left)
    {
        printRightBoundaryTopToBottom(root->left, rightBoundary);
    }
}

int main()
{
    Node *root = input_tree();

    vector<int> leftBoundary, rightBoundary;


    if (root->left)
        printLeftBoundaryBottomToTop(root->left, leftBoundary);


    if (root->right)
        printRightBoundaryTopToBottom(root->right, rightBoundary);


    for (int val : leftBoundary)
        cout << val << " ";

  
    cout << root->val << " ";


    for (int val : rightBoundary)
        cout << val << " ";

    return 0;
}
