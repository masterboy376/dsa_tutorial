#include "bits/stdc++.h"
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigZagTraversal(node *root)
{ // O(n)
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        if (n != NULL)
        {
            cout << n->data << " ";
            if (level % 2 == 0)
            {
                if (n->left)
                {
                    q.push(n->left);
                }
                if (n->right)
                {
                    q.push(n->right);
                }
            }
            else
            {
                if (n->right)
                {
                    q.push(n->right);
                }
                if (n->left)
                {
                    q.push(n->left);
                }
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
}
void zigZagTraversal2(node *root)
{ // O(n)
    if(root==NULL){
        return;
    }
    stack<node*> currLevel;
    stack<node*> nextLevel;
    bool leftToRight;

    currLevel.push(root);
    while (!currLevel.empty())
    {
        node *temp = currLevel.top();
        currLevel.pop();
        if (temp!=NULL)
        {
            cout << temp->data << " ";

            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main()
{
    node *root = new node(10);
    node *l = new node(5);
    node *ll = new node(3);
    node *lr = new node(9);
    node *r = new node(15);

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;

    zigZagTraversal(root);
    cout << endl;
    zigZagTraversal2(root);
    cout << endl;

    return 0;
}