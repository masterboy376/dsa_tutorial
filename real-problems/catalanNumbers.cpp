#include "bits/stdc++.h"
using namespace std;

/*
applications:
1.possible bst
2.paranthesis/ bracket combinations
3.possible forests
4.ways of triangulations
5.possil=ble paths in matrix
6.dividing a cycle using n chords
7.dyck words of given length & much more
*/

int catalan1(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan1(i) * catalan1(n - i - 1);
    }
    return res;
}

// 1.possible bst from n nodes == catalan of n

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

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

vector<node *> constructTrees(int st, int en)
{
    vector<node *> trees;
    if(st>en){
        trees.push_back(NULL);
        return trees;
    }
    for (int i = st; i <= en; i++)
    {
        vector<node *> leftSubtrees = constructTrees(st, i - 1);
        vector<node *> rightSubtrees = constructTrees(i + 1, en);

        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            node* left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                node* right = rightSubtrees[k];
                node* newNode = new node(i);
                newNode->left=left;
                newNode->right=right;
                trees.push_back(newNode);
            }
        }
    }
    return trees;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << catalan1(i) << endl;
    }

    vector<node*> totalTrees = constructTrees(1,3);
    for( int i = 0; i<totalTrees.size(); i++){
        cout<<(i+1)<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }

    return 0;
}