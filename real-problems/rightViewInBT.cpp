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

void rightView(node *root)
{ // O(n)
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        if (n != NULL)
        {
            if (q.front() == NULL)
            {
                cout << n->data << " ";
            }
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

void rightView2(node *root)
{ // O(n)
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for(int i = 0 ; i<n; i++){
            node* curr = q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}


/*
            10
          /    \
        5       15
       / \
      3   9
*/

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

    rightView(root);
    cout << endl;
    rightView2(root);
    cout << endl;

    return 0;
}