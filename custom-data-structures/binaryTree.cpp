#include "bits/stdc++.h"
using namespace std;
/*
-properties-
1. max nodes at level L = 2^L
2. max nodes in a tree of height H = 2^H - 1
3. for N nodes, min possible height = log2(N+1)
4. a binary tree with L leaves has at least log2(N+1) + 1 number of levels
*/
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    
};

void preTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preTraversal(root->left);
        preTraversal(root->right);
    }
}

void postTraversal(node *root)
{
    if (root != NULL)
    {
        postTraversal(root->left);
        postTraversal(root->right);
        cout << root->data << " ";
    }
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

/*
            10
          /    \
        5       15
       / \     
      3   9
*/

int main()
{
    node * root = new node(10);
    node * l = new node(5);
    node * ll = new node(3);
    node * lr = new node(9);
    node * r = new node(15);

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;

    preTraversal(root);
    cout<<endl;
    inTraversal(root); //sorted array
    cout<<endl;
    postTraversal(root);
    cout<<endl;
    

    return 0;
}