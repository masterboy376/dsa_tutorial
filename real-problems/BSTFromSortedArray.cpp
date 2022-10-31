#include "bits/stdc++.h"
using namespace std;

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

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node* buildBST(int a[], int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = (end+st)/2;
    node* root = NULL;
    root = new node(a[mid]);
    root->left = buildBST(a, st, mid-1);
    root->right = buildBST(a, mid+1, end);
    return root;
}

int main()
{
    int a[7] = {1,2,3,4,5,6,7};
    node* root = buildBST(a, 0, 6);

    inorder(root);
    cout<<endl;

    return 0;
}