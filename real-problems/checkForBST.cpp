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

bool isBST(node* root, node* min, node* max){ // O(n)
    if(root ==NULL){
        return true;
    }
    if(min!=NULL and root->data<=min->data){
        return false;
    }
    if(max!=NULL and root->data>=max->data){
        return false;
    }
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid and rightValid;
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

    cout<<isBST(root,NULL,NULL)<<endl;

    return 0;
}