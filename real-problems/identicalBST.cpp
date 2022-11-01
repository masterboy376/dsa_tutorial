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

bool isIdentical(node* root1, node* root2){
    if(root1==NULL and root2==NULL){
        return true;
    }
    else if(root1==NULL or root2==NULL){
        return false;
    }
    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);
        if(cond1 and cond2 and cond3){
            return true;
        }
        else{
            return false;
        }
    }
}

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

    node * root2 = new node(10);
    node * l2 = new node(5);
    node * ll2 = new node(3);
    node * lr2 = new node(9);
    node * r2 = new node(11);
    root2->left = l2;
    root2->right = r2;
    l2->left = ll2;
    l2->right = lr2;

    cout<<isIdentical(root,root2)<<endl;

    return 0;
}