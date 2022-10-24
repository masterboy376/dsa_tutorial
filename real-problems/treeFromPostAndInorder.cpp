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
node *buildTreeFromPostAndIn(vector<int> Post, vector<int> in, int st, int end)
{
    static int idx = end;
    if (st > end)
    {
        return NULL;
    }
    int curr = Post[idx];
    idx--;
    node *n = new node(curr);
    if (st == end)
    {
        return n;
    }
    int pos = search(in, st, end, curr);
    n->right = buildTreeFromPostAndIn(Post, in, pos + 1, end);
    n->left = buildTreeFromPostAndIn(Post, in, st, pos - 1);
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
    vector<int> Post = {4, 2, 5, 3, 1};
    vector<int> in = {4, 2, 1, 5, 3};

    node *root = buildTreeFromPostAndIn(Post, in, 0, 4);

    inTraversal(root); // sorted array
    cout << endl;

    return 0;
}