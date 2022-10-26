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

int height(node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

bool isBalanced(node* root){ // O(n^2)
    if(root==NULL){
        return true;
    }
    if(!(isBalanced(root->left) && isBalanced(root->right))){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(!(abs(lh-rh)<=1)){
        return false;
    }
    return true;
}
bool isBalanced(node* root, int * h){ // O(n)
    if(root==NULL){
        return true;
    }
    int lh = 0,rh = 0;
    if(!(isBalanced(root->left, &lh) && isBalanced(root->right, &rh))){
        return false;
    }
    *h = max(lh,rh) +1;
    if(!(abs(lh-rh)<=1)){
        return false;
    }
    return true;
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

    int h =0;
    cout<<isBalanced(root, &h)<<endl;

    return 0;
}