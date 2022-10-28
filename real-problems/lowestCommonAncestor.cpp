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

bool getPath(node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }
    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int lowestCommonAncestor(node *root, int n1, int n2)
{ // O(n) + for loop
    vector<int> path1, path2;
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }
    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            return path1[pc - 1];
        }
    }
    return -1;
}

node *lca(node *root, int n1, int n2)
{ // O(n)
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *leftLCA = lca(root->left, n1, n2);
    node *rightLCA = lca(root->right, n1, n2);

    if (leftLCA && rightLCA)
    {
        return root;
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    return rightLCA;
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

    cout << lowestCommonAncestor(root, 3, 9) << endl;
    cout << lca(root, 3, 15)->data<< endl;

    return 0;
}