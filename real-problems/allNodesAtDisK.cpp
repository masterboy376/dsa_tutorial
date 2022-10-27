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

// case 1
void printSubTreeNodes(node* root, int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubTreeNodes(root->left, k-1);
    printSubTreeNodes(root->right, k-1);
}

// case 2
int printNodesAtDisK(node* root, node* target, int k){
    if(root ==NULL){
        return -1;
    }
    if(root == target){
        printSubTreeNodes(root,k);
        return 0;
    }
    int dl = printNodesAtDisK(root->left, target, k);
    if(dl!=-1){
        if(dl + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            printNodesAtDisK(root->right, target, k-dl-2);
        }
        return dl+1;
    }
    int dr = printNodesAtDisK(root->right, target, k);
    if(dr!=-1){
        if(dr + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            printNodesAtDisK(root->left, target, k-dr-2);
        }
        return dr+1;
    }
    return -1;
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
     
    printNodesAtDisK(root, root->left, 1);
    cout<<endl;

    return 0;
}