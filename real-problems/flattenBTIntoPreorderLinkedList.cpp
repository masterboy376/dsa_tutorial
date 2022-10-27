#include "bits/stdc++.h"
using namespace std;

// 10 -> 5 -> 3 -> 9 ->15

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

void flatten(node* root){
    if(root ==NULL||(root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        node* temp = root->right;
        root->right=root->left;
        root->left=NULL;

        node* tail = root->right;
        while(tail->right!=NULL){
            tail=tail->right;
        }

        tail->right = temp;
    }
    flatten(root->right);
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
     
    flatten(root);
    inTraversal(root);
    cout<<endl;

    return 0;
}