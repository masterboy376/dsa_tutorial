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

node* lowestCommanAncestor(node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* left = lowestCommanAncestor(root->left, n1, n2);
    node* right = lowestCommanAncestor(root->right, n1, n2);

    if(left!=NULL and right!=NULL){
        return root;
    }
    else if(left==NULL and right==NULL){
        return NULL;
    }
    else if(left!=NULL){
        return lowestCommanAncestor(root->left, n1,n2);
    }
    else{
        return lowestCommanAncestor(root->right, n1,n2);
    }
}

int findDis(node* root, int k , int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist;
    }
    int left = findDis(root->left, k, dist+1);
    if(left!=-1){
        return left;
    }
    int right = findDis(root->right, k, dist+1);
    return right;
}

int disBtwTwoNodes(node* root, int n1, int n2){
    node* lca = lowestCommanAncestor(root, n1,n2);
    int d1 = findDis(lca,n1,0);
    int d2 = findDis(lca,n2,0);
    return (d1+d2);
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

    cout<<disBtwTwoNodes(root,9,15)<<endl;

    return 0;
}