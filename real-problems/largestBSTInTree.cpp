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

struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBST(node* root){
    if(root==NULL){
        return {0, INT32_MIN, INT32_MAX, 0, true};
    }
    if(root->left==NULL and root->right==NULL){
        return {1, root->data, root->data, 1, true};
    }

    info leftInfo = largestBST(root->left);
    info rightInfo = largestBST(root->right);
    info currInfo;
    currInfo.size = leftInfo.size+rightInfo.size+1;
    if(leftInfo.isBST and rightInfo.isBST and leftInfo.max<root->data and rightInfo.min>root->data){
        currInfo.min = min(leftInfo.min, min(rightInfo.min, root->data));
        currInfo.max = max(leftInfo.max, max(rightInfo.max, root->data));
        currInfo.ans = currInfo.size;
        currInfo.isBST = true;
        return currInfo;
    }
    currInfo.ans = max(leftInfo.ans , rightInfo.ans);
    currInfo.isBST = false;
    return currInfo;
    
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

    cout<<largestBST(root).ans<<endl;

    return 0;
}