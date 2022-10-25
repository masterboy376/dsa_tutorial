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

void inTraversal(node *root)
{
    if (root != NULL)
    {
        inTraversal(root->left);
        cout << root->data << " ";
        inTraversal(root->right);
    }
}

void sumReplacement(node* root){ //O(n)
    if(root==NULL){
        return;
    }
    sumReplacement(root->left);
    sumReplacement(root->right);
    if(root->left!=NULL){
        root->data += root->left->data;
    }
    if(root->right!=NULL){
        root->data += root->right->data;
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

    sumReplacement(root);

    inTraversal(root); //sorted array
    cout<<endl;

    return 0;
}