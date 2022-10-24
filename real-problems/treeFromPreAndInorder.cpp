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

int search(vector<int> in, int st, int end, int target)
{
    for (int j = st; j <= end; j++)
    {
        if (in[j] == target)
        {
            return j;
        }
    }
    return -1;
}
node *buildTreeFromPreAndIn(vector<int> pre, vector<int> in, int st, int end)
{
    static int idx = 0;
    if (st > end)
    {
        return NULL;
    }
    int curr = pre[idx];
    idx++;
    node *n = new node(curr);
    if (st == end)
    {
        return n;
    }
    int pos = search(in, st, end, curr);
    n->left = buildTreeFromPreAndIn(pre, in, st, pos - 1);
    n->right = buildTreeFromPreAndIn(pre, in, pos + 1, end);
    return n;
}

void inTraversal(node *root)
{
    if (root != NULL)
    {
        inTraversal(root->left);
        cout << root->data << " ";
        inTraversal(root->right);
    }
}

int main()
{
    vector<int> pre = {1, 2, 4, 3, 5};
    vector<int> in = {4, 2, 1, 5, 3};

    node *root = buildTreeFromPreAndIn(pre, in, 0, 4);

    inTraversal(root); // sorted array
    cout << endl;

    return 0;
}